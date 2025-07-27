# Lens Recommendation System (ESP32)

## Overview

This project implements a machine learning-based recommendation system for fitting contact lenses, using the classic lenses dataset. The system includes:

- Data analysis and model training in Python (Jupyter Notebook)
- Model export to TensorFlow Lite and deployment on an ESP32 microcontroller
- Example code for running the model on ESP32 hardware

## Directory Structure

```
Lenses_CP3project/
│
├── ESP32/
│   └── LensesClassifyModel/
│       ├── LensesClassifyModel.ino        # Arduino sketch for ESP32 inference
│       └── lenses_model_esp32.h           # TFLite model as C header array
│
├── lenses/
│   ├── lenses.csv                         # Main dataset (CSV)
│   ├── lenses.data                        # Dataset (space-separated)
│   ├── lenses.names                       # Dataset description/metadata
│   └── Index                              # Index of files
│
├── LensesClassifyModel.h5                 # Trained Keras/TensorFlow model
├── LensesClassifyModel.tflite             # TensorFlow Lite model
├── Main.ipynb                             # Jupyter notebook for data analysis & training
├── saved_lenses_model_dir/                # TensorFlow SavedModel directory
│   ├── saved_model.pb
│   ├── variables/
│   └── assets/
```

## Dataset

- **Source:** [UCI Machine Learning Repository - Lenses Data Set](https://archive.ics.uci.edu/ml/datasets/Lenses)
- **Description:**
  - 24 instances, 4 attributes (age, prescription, astigmatic, tear_rate)
  - 3 classes: hard lens, soft lens, no lens
  - See `lenses/lenses.names` for full details

## Model Training (Python)

- All data analysis, visualization, and model training is performed in `Main.ipynb` using TensorFlow/Keras.
- The notebook loads the dataset, preprocesses it, trains a neural network, and exports the model to both `.h5` and `.tflite` formats.
- The trained model is also saved as a TensorFlow SavedModel in `saved_lenses_model_dir/`.

### How to Run (Python)

1. Install dependencies:
   ```bash
   pip install pandas numpy matplotlib tensorflow
   ```
2. Open `Main.ipynb` in Jupyter Notebook or JupyterLab.
3. Run all cells to reproduce the analysis and model training.

## ESP32 Deployment

- The TFLite model is converted to a C header (`lenses_model_esp32.h`) for use with the [EloquentTinyML](https://github.com/eloquentarduino/EloquentTinyML) library on ESP32.
- The Arduino sketch (`LensesClassifyModel.ino`) demonstrates loading the model and running inference on example inputs.

### How to Run (ESP32)

1. Install the [EloquentTinyML](https://github.com/eloquentarduino/EloquentTinyML) library in the Arduino IDE.
2. Open `LensesClassifyModel.ino` in the Arduino IDE.
3. Ensure `lenses_model_esp32.h` is in the same directory as the `.ino` file.
4. Connect your ESP32 board and upload the sketch.
5. Open the Serial Monitor to view inference results.

## File Descriptions

- **Main.ipynb**: Data analysis, visualization, and model training notebook
- **LensesClassifyModel.h5**: Trained Keras/TensorFlow model (for further training or conversion)
- **LensesClassifyModel.tflite**: TensorFlow Lite model (for microcontroller deployment)
- **ESP32/LensesClassifyModel.ino**: Arduino sketch for running the model on ESP32
- **ESP32/lenses_model_esp32.h**: Model weights as a C array for ESP32
- **lenses/**: Contains the dataset and metadata
- **saved_lenses_model_dir/**: TensorFlow SavedModel (for serving or conversion)

## Credits

- Dataset: UCI Machine Learning Repository
- Model conversion: TensorFlow, EloquentTinyML
- Project author: [Your Name Here]

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
