# Import required libraries
import re
import tkinter as tk
import pandas as pd
import numpy as np
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
import nltk

# Download NLTK stopwords
nltk.download('stopwords')

# Load Netflix data
data = pd.read_csv('netflixData.csv')
data = data.dropna(subset=['Cast', 'Production Country', 'Rating'])

# Filter movies and TV shows
movies = data[data['Content Type'] == 'Movie'].reset_index()
movies = movies.drop(['index', 'Show Id', 'Content Type', 'Date Added',
                    'Release Date', 'Duration', 'Description'], axis=1)

tv = data[data['Content Type'] == 'TV Show'].reset_index()
tv = tv.drop(['index', 'Show Id', 'Content Type', 'Date Added',
            'Release Date', 'Duration', 'Description'], axis=1)

# Tokenize and process data
def tokenize_and_process(data, column_name):
    items = []
    for item in data[column_name]:
        if pd.notna(item):
            item_tokens = re.split(r', \s*', item)
            items.append(item_tokens)

    flat_list = [item for sublist in items for item in sublist]
    unique_items = sorted(set(flat_list))
    binary_data = [[0] * 0 for _ in range(len(unique_items))]
    
    for item in data[column_name]:
        k = 0
        for j in unique_items:
            if pd.isna(item):
                binary_data[k].append(0.0)
            elif j in item:
                binary_data[k].append(1.0)
            else:
                binary_data[k].append(0.0)
            k += 1

    return pd.DataFrame(binary_data).transpose(), unique_items

# Process actors, directors, countries, genres, and ratings for movies
binary_actors, actors_list = tokenize_and_process(movies, 'Cast')
binary_directors, directors_list = tokenize_and_process(movies, 'Director')
binary_countries, countries_list = tokenize_and_process(movies, 'Production Country')
binary_genres, genres_list = tokenize_and_process(movies, 'Genres')
binary_ratings, ratings_list = tokenize_and_process(movies, 'Rating')

# Concatenate movie binary data
binary = pd.concat([binary_actors, binary_directors, binary_countries, binary_genres], axis=1, ignore_index=True)

# Process actors, countries, genres, and ratings for TV shows
binary_actors_2, actors_list_2 = tokenize_and_process(tv, 'Cast')
binary_countries_2, countries_list_2 = tokenize_and_process(tv, 'Production Country')
binary_genres_2, genres_list_2 = tokenize_and_process(tv, 'Genres')
binary_ratings_2, ratings_list_2 = tokenize_and_process(tv, 'Rating')

# Concatenate TV show binary data
binary_2 = pd.concat([binary_actors_2, binary_countries_2, binary_genres_2], axis=1, ignore_index=True)

# Create a Tkinter window
window = tk.Tk()
window.geometry('600x600')
head = tk.Label(window, text='Enter Movie / TV Show on Netflix For Recommendations', font=('Calibri 15'))
head.pack(pady=20)

# Define the recommendation function
def netflix_recommender(search):
    cs_list = []
    binary_list = []

    def calculate_cosine_similarity(point_1, point_2):
        dot_product = np.dot(point_1, point_2)
        norm_1 = np.linalg.norm(point_1)
        norm_2 = np.linalg.norm(point_2)
        cos_sim = dot_product / (norm_1 * norm_2)
        return cos_sim

    if search in movies['Title'].values:
        idx = movies[movies['Title'] == search].index.item()
        for i in binary.iloc[idx]:
            binary_list.append(i)

        point_1 = np.array(binary_list).reshape(1, -1)
        point_1 = [val for sublist in point_1 for val in sublist]
        for j in range(len(movies)):
            binary_list_2 = []
            for k in binary.iloc[j]:
                binary_list_2.append(k)
            point_2 = np.array(binary_list_2).reshape(1, -1)
            point_2 = [val for sublist in point_2 for val in sublist]
            cos_sim = calculate_cosine_similarity(point_1, point_2)
            cs_list.append(cos_sim)

        movies_copy = movies.copy()
        movies_copy['cos_sim'] = cs_list
        results = movies_copy.sort_values('cos_sim', ascending=False)
        results = results[results['Title'] != search]
        top_results = results.head(5)
        return top_results

    elif search in tv['Title'].values:
        idx = tv[tv['Title'] == search].index.item()
        for i in binary_2.iloc[idx]:
            binary_list.append(i)

        point_1 = np.array(binary_list).reshape(1, -1)
        point_1 = [val for sublist in point_1 for val in sublist]
        for j in range(len(tv)):
            binary_list_2 = []
            for k in binary_2.iloc[j]:
                binary_list_2.append(k)
            point_2 = np.array(binary_list_2).reshape(1, -1)
            point_2 = [val for sublist in point_2 for val in sublist]
            cos_sim = calculate_cosine_similarity(point_1, point_2)
            cs_list.append(cos_sim)

        tv_copy = tv.copy()
        tv_copy['cos_sim'] = cs_list
        results = tv_copy.sort_values('cos_sim', ascending=False)
        results = results[results['Title'] != search]
        top_results = results.head(5)
        return top_results

    else:
        return 'Title not in dataset. Please check spelling.'

# Function to handle button click
def call_recommender():
    subject = text.get()
    recommendation = netflix_recommender(subject)
    txt = ''
    for _, row in recommendation.iterrows():
        txt += f'Title: {row["Title"]}\n'
    tk.Label(window, text=txt, font=('Calibri 15')).place(x=195, y=150)

# Create input field and button
text = tk.StringVar()
tk.Entry(window, textvariable=text).place(x=200, y=80, height=30, width=280)
tk.Button(window, text='Find Recommendations', command=call_recommender).place(x=285, y=150)

# Start the Tkinter window
window.mainloop()
