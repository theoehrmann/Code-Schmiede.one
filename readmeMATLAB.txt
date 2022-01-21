This is from my project on pg.12 of my portfolio

dragForce.xlsx:
- The data is orientated transversly to what it should be, this is fixed in the matlab code
- There are 156 seperate experiments
- rows 1 to 4 = variables
1=T
2=C
3=W
4=F
- row 5 = goal
5=drag force

Model.m:
- Split data 75:25 and apply transverse
- Training and testing linear and non-linear regression
- Deriving r^2 and rsme for regressions
- Selection and creation of objective function (objr)

Optimisation.m
- Importing data and objective function
- Setting up constraints in arrays
- Optimisation using GA and sqp and recording time taken to process

