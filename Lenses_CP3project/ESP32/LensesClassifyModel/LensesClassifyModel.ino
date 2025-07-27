#include <EloquentTinyML.h>
// This file contains the TFLite model generated from the Lenses dataset
#include "lenses_model_esp32.h"

// Lenses dataset feature details
// Datal cols = ['age', 'prescription', 'astigmatic', 'tear_rate']
// Attribute values:
// - age: young (1), pre-presbyopic (2), presbyopic (3)
// - prescription: myope (1), hypermetrope (2)
// - astigmatic: no (1), yes (2)
// - tear_rate: reduced (1), normal (2)
// Output Categories are: 
// - hard lens (1), soft lens (2), no lens (3)

#define NUMBER_OF_INPUTS 9  
#define NUMBER_OF_OUTPUTS 3 
#define TENSOR_ARENA_SIZE 5*1024  // Adjust as needed for model size

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

void setup() {
    Serial.begin(115200);
   
    ml.begin(lenses_model_esp32);
}

float fResult[NUMBER_OF_OUTPUTS] = {0};
float fRes = NULL;

void loop() {
    // Example inputs representing different combinations for the lenses dataset

    // Input 1: age=young, prescription=myope, astigmatic=no, tear_rate=normal
    float input1[] = {1.0f, 0.0f, 0.0f,  // age (young)
                      1.0f, 0.0f,        // prescription (myope)
                      1.0f, 0.0f,        // astigmatic (no)
                      0.0f, 1.0f};       // tear_rate (normal)
    // Expected output: (e.g., no lens)

    // Input 2: age=presbyopic, prescription=hypermetrope, astigmatic=yes, tear_rate=reduced
    float input2[] = {0.0f, 0.0f, 1.0f,  // age (presbyopic)
                      0.0f, 1.0f,        // prescription (hypermetrope)
                      0.0f, 1.0f,        // astigmatic (yes)
                      1.0f, 0.0f};       // tear_rate (reduced)
    // Expected output: (e.g., hard lens)

    // Run inference on each input and display results
    testInput(input1, "Input1");
    testInput(input2, "Input2");

    delay(5000);  // Delay between each test
}

void testInput(float* input, const char* inputName) {
    initfResult(fResult);
    fRes = ml.predict(input, fResult);
    Serial.print("\nThe output value returned for ");
    Serial.print(inputName);
    Serial.print(" is:\n");
    Serial.println(fRes);
    displayOutput(fResult);
}

void initfResult(float *fResult) {
    for (int i = 0; i < NUMBER_OF_OUTPUTS; i++) {
       fResult[i] = 0.0f;
    }
}

void displayOutput(float *fResult) {
    Serial.print("Output probabilities: ");
    for (int i = 0; i < NUMBER_OF_OUTPUTS; i++) {
        Serial.print(fResult[i]);
        Serial.print(" ");
    }
    Serial.println();
}
