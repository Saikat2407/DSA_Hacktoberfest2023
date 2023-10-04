import csv
import numpy as np
import random
from sklearn.linear_model import LogisticRegression
import ml_helpers

# Read a CSV file into a list of tuples
def csv_to_list(file_name):
	new_list = []
	# The "with" statement goes through the whole file and closes it once its done
	with open(file_name, 'r') as csv_file:
		reader = csv.reader(csv_file)
		
		# For ever row in the CSV file
		for row in reader:
			# Only use the proper columns
			content = tuple(row)
			new_list.append(content)
	return new_list

# Get the training data
data = np.asarray(csv_to_list("wine_data.csv"), dtype=np.float32)
train_data = data[:, 1:]
train_labels = data[:, 0]

train_data, train_labels = ml_helpers.shuffle_data(train_data, train_labels)

# Normalize the training data
train_data = ml_helpers.normalize_data(train_data)

num_epochs = 3
learning_rate = 0.01
reg = 0.1

unique_labels = np.unique(train_labels)
num_classes = len(unique_labels)

num_features = train_data.data.shape[1]
weights = np.zeros((num_features + 1, num_classes))

final_predictions = [0] * len(train_labels)

# *********************************************
# Perform Logistic Regression manually
# We will use a ONE vs ALL scheme
# *********************************************
for curr_epoch in range(num_epochs):

	cost = 0
	gradient_error = np.zeros((num_features + 1, num_classes))
	for index, sample in enumerate(train_data):

		curr_label = int(train_labels[index])
		one_hot_index = np.where(unique_labels == curr_label)
		curr_one_hot_labels = np.zeros(num_classes)
		curr_one_hot_labels[one_hot_index] = 1

		class_predictions = np.zeros(num_classes)

		for class_index in range(num_classes):
			class_predictions[class_index] = weights[1:, class_index].dot(sample) + weights[0, class_index]
			
		
		class_predictions = ml_helpers.sigmoid(class_predictions)

		cost = cost +  -1*np.sum((curr_one_hot_labels.dot(np.log(class_predictions)) + (1 - curr_one_hot_labels).dot(np.log(1 - class_predictions))))  + (reg * np.sum(weights ** 2, axis=1))

		reg_array = np.append(0, np.full(num_features, reg))

		for class_index in range(num_classes):
			gradient_error[:, class_index] = gradient_error[:, class_index] + (curr_one_hot_labels[class_index] - class_predictions[class_index])*np.append(1, sample) + (reg_array * weights[:, class_index])

		if curr_epoch == num_epochs - 1:
			final_predictions[index] = class_predictions

	weights = weights + learning_rate * (gradient_error / len(train_labels))

	print("Epoch # ", curr_epoch + 1, " with cost = ", cost)


# ***************************************************************
# Perform Logistic Regression using Sklean
# ***************************************************************
lm = LogisticRegression()
lm.fit(train_data, train_labels)
sklearn_predictions = lm.predict(train_data)

# Test out the training accuracy
Accuracy = 0
for pred_idx, pred in enumerate(final_predictions):
	pred_class_index = np.argmax(pred)
	# pred_class_index = list(unique_labels).index(pred) # FOR THE Sklean LOGISTIC REGRESSION. ALSO SUB IN "predictions" instead of "sklearn_predictions"

	curr_label = int(train_labels[pred_idx])
	one_hot_index = list(unique_labels).index(curr_label)
	
	if pred_class_index == one_hot_index:
		Accuracy = Accuracy + 1

Accuracy = Accuracy / len(final_predictions)

print("Final classification accuracy = ", Accuracy)
