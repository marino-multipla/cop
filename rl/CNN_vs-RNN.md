Convolutional Neural Networks (CNNs) and Recurrent Neural Networks (RNNs) are two types of neural networks commonly used for different types of tasks in machine learning. Here's a detailed comparison of the two:

### Convolutional Neural Networks (CNNs)

**1. Structure and Function:**
   - **Convolutions:** CNNs use convolutional layers that apply filters (kernels) to input data to create feature maps. These filters can detect patterns such as edges, textures, or more complex shapes in images.
   - **Pooling:** CNNs typically include pooling layers (e.g., max pooling) to reduce the spatial dimensions of the feature maps, which helps reduce the number of parameters and computation.
   - **Fully Connected Layers:** After several convolutional and pooling layers, the output is usually flattened and fed into fully connected (dense) layers for classification or regression tasks.

**2. Typical Use Cases:**
   - **Image Processing:** CNNs are highly effective for image classification, object detection, and segmentation due to their ability to capture spatial hierarchies in images.
   - **Computer Vision:** Used in tasks like facial recognition, image generation, and more.

**3. Key Characteristics:**
   - **Spatial Hierarchy:** CNNs excel at capturing spatial hierarchies and local dependencies in data.
   - **Parameter Sharing:** Filters (kernels) are shared across the entire input space, which reduces the number of parameters and computational cost.
   - **Translation Invariance:** CNNs are robust to translations in input data, meaning they can recognize patterns regardless of their position in the input.

**4. Example Code:**

```python
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense

model = Sequential([
    Conv2D(32, (3, 3), activation='relu', input_shape=(64, 64, 3)),
    MaxPooling2D(pool_size=(2, 2)),
    Conv2D(64, (3, 3), activation='relu'),
    MaxPooling2D(pool_size=(2, 2)),
    Flatten(),
    Dense(128, activation='relu'),
    Dense(10, activation='softmax')
])

model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])
```

### Recurrent Neural Networks (RNNs)

**1. Structure and Function:**
   - **Recurrent Connections:** RNNs have recurrent connections that create loops in the network, allowing them to maintain a hidden state that can capture information from previous time steps.
   - **Hidden State:** At each time step, the hidden state is updated based on the input and the previous hidden state, enabling the network to capture temporal dependencies.

**2. Typical Use Cases:**
   - **Sequence Data:** RNNs are well-suited for tasks involving sequential data, such as time series forecasting, natural language processing (NLP), and speech recognition.
   - **Language Models:** Used in language modeling, translation, text generation, and more.

**3. Key Characteristics:**
   - **Temporal Dependencies:** RNNs are designed to capture temporal dependencies and sequential patterns in data.
   - **Context Preservation:** They can retain information from previous inputs to inform current and future predictions.
   - **Vanishing/Exploding Gradients:** Traditional RNNs can suffer from vanishing or exploding gradients, making it difficult to learn long-term dependencies. Variants like LSTM (Long Short-Term Memory) and GRU (Gated Recurrent Unit) are designed to address these issues.

**4. Example Code:**

```python
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import SimpleRNN, Dense

model = Sequential([
    SimpleRNN(128, input_shape=(100, 1), activation='relu'),
    Dense(10, activation='softmax')
])

model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])
```

### Summary

- **CNNs:** 
  - **Strengths:** Excellent at spatial data processing (images, videos), capturing local dependencies, and handling translation invariance.
  - **Applications:** Image classification, object detection, image segmentation, computer vision tasks.

- **RNNs:**
  - **Strengths:** Ideal for sequential data, capturing temporal dependencies, and maintaining contextual information over sequences.
  - **Applications:** Time series analysis, speech recognition, language modeling, translation, text generation.

Choosing between CNNs and RNNs depends on the nature of your data and the specific requirements of your task. For tasks involving spatial data, CNNs are typically more effective, whereas RNNs are more suitable for tasks involving sequential or temporal data.