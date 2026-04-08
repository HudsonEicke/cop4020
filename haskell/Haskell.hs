shortPi :: Double
shortPi = 4 * atan(1 / 5) - atan(1 /239)

simplePi :: Double -> Double
simplePi x = 
  if x == 0 then 0 --base case
  else (((-1) ** (x + 1))/(2 * x - 1)) + simplePi (x - 1) --otherwise do formula added to recursive call

wellsPi :: Double -> Double
wellsPi x = 
  if x == 0 then 0 --base case
  else (1 / ((2 * x - 1) ** 2)) + wellsPi (x - 1) --otherwise do formula added to recursive call
  
nSquaredSeries :: Double -> Double
nSquaredSeries x =
  if x == 0 then 0 --base case
  else (1 / (x ** 2)) + nSquaredSeries (x - 1) --otherwise do formula added to recursive call

eulerPi :: Double -> Double
eulerPi x = (6 * nSquaredSeries x) ** 0.5 --do multiply 1/n^2 series and then sqrt

wallisFormula :: Double -> Double
wallisFormula x = 
  if x == 0 then 1 --different base case for multiplication
  else (((2 * x) ** 2) / ((2 * x - 1) * (2 * x + 1))) * wallisFormula (x - 1) --otherwise do formula and multiply by recursive call

main :: IO ()
main = do
  --convert short pi to pi since value does not correspond to actual pi value
  let shortPiRes = (shortPi) * 4
  print ("Short pi value = " ++ show(shortPiRes))
  
  --convert simple pi to pi since value does not correspond to actual pi value
  let simplePiRes = (simplePi 200) * 4
  print ("Simple pi value = " ++ show(simplePiRes))
  
  --convert welles pi to pi
  --The most accurate Pi calculation is Welles Pi since value does not correspond to actual pi value
  let wellesPiRes = ((wellsPi 200) * 8) ** 0.5
  print ("Welles pi value = " ++ show(wellesPiRes))
  
  let eulerPiRes = eulerPi 200
  print ("Euler pi value = " ++ show(eulerPiRes))
  
  --convert wallis formula to pi since formula does not correspond to actual pi value
  let wallisFormulaRes = (wallisFormula 200) * 2
  print ("Wallis formula value = " ++ show(eulerPiRes))
  
  return()
