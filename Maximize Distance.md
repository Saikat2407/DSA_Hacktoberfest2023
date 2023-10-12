## Maximize Distance to Closest Person

Given an array representing a row of seats where `seats[i] = 1` represents a person sitting in the `i`th seat, and `seats[i] = 0` represents that the `i`th seat is empty (0-indexed).

### Problem Statement

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.

### Solution

To maximize the distance to the closest person in a row of seats, you can use the following Python function:

```python
def maxDistToClosest(seats):
    max_distance = 0
    prev_person_index = -1

    for i, seat in enumerate(seats):
        if seat == 1:
            if prev_person_index == -1:
                # If the first person is sitting at seat 0
                max_distance = i
            else:
                # Calculate distance between two people
                max_distance = max(max_distance, (i - prev_person_index) // 2)
            prev_person_index = i

    # Calculate distance from the last person to the last empty seat
    max_distance = max(max_distance, len(seats) - 1 - prev_person_index)

    return max_distance

# Example usage:
seats = [1, 0, 0, 0, 1, 0, 1]
result = maxDistToClosest(seats)
print(result)  # Output: 2
```
This code iterates through the seats, **keeping track of the previous person's index** and **calculating the maximum distance between two people** or between a person and an empty seat. **It returns the maximum distance to the closest person**.

