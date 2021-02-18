# Wells Fargo

## TimeSeries
- I've designed a fixed capacity time series object. The capacity is determined at creation.
- Time is denoted by an integer from some epoch. The start of the window is also supplied at creation. If this is not supplied we assume the window starts at the epoch. 
We assume that the resolution of time cannot get finer than a second.
- Three cases of individual entries can be made to this time series. The new data point can lie a) in the original range, b) to the right of the range, or c) to the left of the range. 
While the a) and b) could be used in live pricing, the use case for c) might involve backtesting.
- In case a) the values are inserted in the array in-place.
- In case b) we shift the array to the right while while padding the missing values and terminating with the new data point.
- In case c) we shift the array to the left while starting with the new data point and padding the missing values to the right.
- The getter throws an error if the queried timestamp does not lie in the range of values in the time series.
- I have added 3 test cases corresponding to the scenarios a)- c) above.

## Patterns
- The patterns project generates patterns based off an 8-bit rule (as described in the pdf). 
- I made use of the 8 bit binary representation of the rule to determine the state of each position of the next row. This is used to 
construct a dictionary which is referenced in the following step.
- Each cluster of 3 adjoining positions of the current row determines the state of the centered position in the subsequent row.
- Special care is taken for the boundaries.
- Escape conditions are implemented (a) either when the limit of the number of generated rows is reached or 
b) if two identical rows appear consecutively before the limiting condition is reached. 
- The number of generated rows is returned by the function.
- I have not attempted to make the code bulletproof (as instructed).
- Test cases corresponding to the patterns printed in the pdf are demonstrated.
