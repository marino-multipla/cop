# nn.ReLU

ReLU(x)=(x)+=max(0,x)

Non-linear activations are what create the complex mappings between the model’s inputs and outputs. They are applied after linear transformations to introduce nonlinearity, helping neural networks learn a wide variety of phenomena.

In this model, we use nn.ReLU between our linear layers, but there’s other activations to introduce non-linearity in your model.

## Why non linearity is needed?
The need for non-linearity in neural networks arises from the fact that linear operations (such as matrix multiplications in the case of linear layers) can only model linear relationships between inputs and outputs. If a neural network consisted only of linear operations, it would effectively behave like a linear model, regardless of how many layers it has. This limitation would severely restrict the model's capacity to learn complex patterns and representations from the data.

By introducing non-linear activation functions, such as Rectified Linear Unit (ReLU), sigmoid, tanh, or others, after linear transformations, the neural network gains the ability to model and capture non-linear relationships within the data. Here's why non-linearity is crucial:

    Expressiveness: Non-linear activation functions introduce non-linearity to the model, allowing it to learn and represent more complex and intricate patterns in the data. This increased expressiveness enables neural networks to approximate a wider variety of functions and mappings.

    Representation Power: Neural networks with non-linear activations become powerful function approximators. The stacking of multiple non-linear layers enables the network to learn hierarchical and abstract features, capturing representations at different levels of abstraction.

    Feature Learning: Non-linear activation functions allow the model to learn hierarchical features from the input data. As the data passes through each layer with non-linear activations, the network can extract increasingly abstract and sophisticated features, contributing to its ability to understand complex relationships.

    Capacity for Learning Diverse Phenomena: Many real-world phenomena are inherently non-linear. For instance, the relationship between inputs and outputs in image recognition, natural language processing, and various other domains is often complex and non-linear. Non-linear activation functions empower the model to capture and understand these intricate relationships.

In summary, non-linear activation functions are essential in neural networks because they break the linearity of the model, enabling it to learn and represent complex relationships in the data. This non-linearity is crucial for the neural network's ability to understand, generalize, and adapt to a wide range of phenomena in different domains.
