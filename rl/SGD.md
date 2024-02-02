# SGD stands for Stochastic Gradient Descent.

**Stochastic Gradient Descent (SGD):**

SGD is an optimization algorithm commonly used in training machine learning models, especially in the context of neural networks. It is a variant of the gradient descent optimization algorithm but introduces a stochastic element.

In traditional gradient descent, the algorithm computes the gradient of the loss function with respect to the model parameters using the entire training dataset. It then updates the parameters in the opposite direction of the gradient to minimize the loss. This process is computationally expensive, especially for large datasets.

SGD, on the other hand, uses a random subset of the training data (a mini-batch) to compute an estimate of the gradient. It then updates the model parameters based on this estimate. The use of mini-batches introduces stochasticity into the optimization process.

The update rule for a parameter \(\theta\) in SGD is given by:

\[ \theta_{t+1} = \theta_t - \alpha \nabla L(\theta_t; x_i, y_i) \]

where:
- \(\theta_t\) is the parameter vector at iteration \(t\),
- \(\alpha\) is the learning rate,
- \(\nabla L(\theta_t; x_i, y_i)\) is the gradient of the loss with respect to \(\theta_t\) computed on a mini-batch (\(x_i, y_i\)).

The use of stochasticity can introduce noise into the parameter updates, but it often helps the optimization process escape local minima and can lead to faster convergence, especially for large datasets.

In practice, there are variations of SGD, such as mini-batch SGD, where the model parameters are updated based on a small random subset of the training data. This balances the computational efficiency of stochastic updates with the stability of using more information than just a single data point.