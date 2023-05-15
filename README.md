# Repository: Machine-Learning
Contains course projects from 3 courses at UZH:
1. four selected files (*iML_w08* - *iML_w12*), from the course 22HS ML Machine Learning - an Interdisciplinary Introduction
2. a folder "*Eye-tracking*", contained 2 course works from 23FS Eye-trakcing - experiment design and machine learning methods
3. four team projects projects (*FDS_1* - *FDS_3*) with Zihan ZHANG (Zihan-Zhang) for the course 22HS Foundations of Data Science (Informatics MS core course)

*created at 15-May-2023*

*last update: 16-May-2023*

# Contents
iML_w12:
forecast time series data using LSTM RNN

iML_w11:
designed a ML/DL algorithm to help determine/predict whether a patient is non-diabetic (int 0) or diabetic (int 1)

iML_w09:
studied the toxicity of molecules, which are described using the simplified molecular input line entry system (SMILES). The system allows to describe the structure of chemical species in the form of a line notation, making it suited for a machine learning approach

iML_w08:
trained an SVM model on court proceeding texts from the European Court of Human Rights and learns whether there has been a violation against a specific article of the European Convention on Human Rights or not

ET_5.ipynb:
implemented an SVM model to classify the gender of a reader based on eye-tracking data. Eye-tracking data taken from the Potsdam Textbook Corpus (https://osf.io/dn5hp/files).

ET_3.py:
used two algorithms to determine fixation period from eye-tracking data (in 60Hz and 2000Hz) and plotted the graphs.
- 2000Hz_Trial16_velocity_5.0_pxms_200ms).png:
- the result file from ET_3.py using velocity algorithm
- 2000Hz_Trial13_dispersion_20.0px_200ms).png:
- the result file from ET_3.py using dispersion algorithm

FDS_3_CIFAR-10.ipynb:
used transfer learning to build a convolutional neural network to tackle the CIFAR-10 dataset (https://www.cs.toronto.edu/~kriz/cifar.html)

FDS_3_MNIST.ipynb:
built a CNN to classify the handwritten digits from the MNIST dataset (http://yann.lecun.com/exdb/mnist/)

FDS_2.ipynb:
comparing the Naïve Bayes Classifier (NBC) and Logistic Regression on several datasets. reproduced some of the experimental results in the paper: *On Discriminative vs. Generative classifiers: A comparison of logistic regression and naive Bayes*, by Andrew Y. Ng and Michael I. Jordan.

FDS_1.ipynb:
implemented and trained a linear regression model using the least squares method on the winequality dataset using the NumPy library. Learning curves will be plotted to determine if the model is overfitting or underfitting.
applied the basis expansion to the dataset and trained linear regression models with regularization, i.e., Ridge and Lasso., using the functions from the scikit-learn library.
