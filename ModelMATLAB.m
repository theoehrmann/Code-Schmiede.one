clear

data = xlsread("dragForce.xlsx");  % Read the data set from solidworks flow parametric study

splitPt1 = fix(0.75*length(data));  % Split the data with 75% for training and 25% for testing

trainVar = data(1:end-1, 1:splitPt1)';  % Training data
trainGoal = data(end, 1:splitPt1)';

testVar = data(1:end-1, splitPt1+1:end)';  % Test Data
testGoal = data(end, splitPt1+1:end)';

beta = mvregress(trainVar, trainGoal);  % Linear Regression
beta2 = fitlm(trainVar, trainGoal);  % R^2 and rmse

poly1 = polyfitn(trainVar, trainGoal, 1);  % linear polynomial 

poly2 = polyfitn(trainVar, trainGoal, 2);  % non-linear plynomial ^2

poly3 = polyfitn(trainVar, trainGoal, 3);  % non-linear plynomial ^3

poly4 = polyfitn(trainVar, trainGoal, 4);  % non-linear plynomial ^4

R2 = (norm(testVar*beta - testGoal)^2/norm(testGoal-mean(testGoal))^2)/1000;  % Linear regression R^2 validation

rmse = sqrt(norm(testVar*beta - testGoal)^2/length(testGoal));  % Linear regression rsme validation

testPoly = polyfitn(testVar, testGoal, 3); % Validating non-linear training data set with test data set

objr = polyn2sympoly(poly4);  % non-linear plynomial ^3 objective function
