esTerna :: Integer -> Integer -> Integer -> Bool
esTerna x y z | x^2 + y^2 == z^2 = True
			  | otherwise = False

terna :: Integer -> Integer -> (Integer, Integer, Integer)
terna x y = (x^2 - y^2, 2*x*y, x^2 + y^2)
