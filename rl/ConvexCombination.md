# Convex Combination

A convex combination is a linear combination of two or more elements, where the coefficients (weights) are non-negative and sum up to 1. In the context of the sentence you provided, mixup trains a neural network on convex combinations of pairs of examples and their labels.

Let's break it down:

    Pairs of examples: This refers to two instances or examples from the dataset.
    Convex combinations: The convex combination of these pairs involves taking a weighted average of their features (input data) and labels, where the weights are non-negative and sum to 1.

Mathematically, for two examples A and B with corresponding labels a and b, a convex combination would be:

Convex Combination=λ⋅A+(1−λ)⋅BConvex Combination=λ⋅A+(1−λ)⋅B

Here, λλ is a weight or coefficient that ranges from 0 to 1. The convex combination smoothly interpolates between the two examples A and B. In the context of training neural networks, mixup uses these convex combinations to generate new training examples, encouraging the model to learn more robust and generalized features.