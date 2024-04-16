
-- 1. Verifique se um elemento pertence a uma lista

pertence :: Int -> [Int] -> Bool
pertence _ [] = False
pertence n (xs:ys) = if n == xs then True else pertence n ys

-- 2. Retorne a intercessãa entre duas listas

intercessao :: [Int] -> [Int] -> [Int]
intercessao [] _ = []
intercessao (x:xs) ys
   | pertence x ys = x : intercessao xs ys
   | otherwise = intercessao xs ys

-- 3. Retorne o inverso de uma lista

inverso :: [Int] -> [Int]
inverso [] = []
inverso (x:xs) = inverso xs ++ [x]

-- 4. Retorne os n ultimos elementos de uma lista

remover :: Int -> [Int] -> [Int]
remover 0 xs = xs
remover n (x:xs) = remover (n-1) xs

nUltimos :: Int -> [Int] -> [Int]
nUltimos _ [] = []
nUltimos n xs = remover (length xs -n) xs

-- 5. Receba 2 listas e some seus valores de mesmo index

soma2 :: [Int] -> [Int] -> [Int]
soma2 _ [] = []
soma2 [] _ = []
soma2 (x:xs) (y:ys) = x+y:soma2 xs ys

-- 6. Receba n e crie uma lista de 2^1 ate 2^n

pot2 :: Int -> [Int]
pot2 1 = [2]
pot2 n = pot2 (n-1) ++ [2^n]

-- 7. Receba duas listas, concatene e ordene

intercalacao :: [Int] -> [Int] -> [Int]
intercalacao xs ys = ordenar(xs++ys)

-- 8. Retorne o menor valor de uma lista

menor :: [Int] -> Int
menor [] = 0
menor [x] = x
menor (x:y:xs) 
   |x > y = menor (y:xs)
   |otherwise = menor (x:xs)

-- 9. Remova o primeiro elemento n de uma lista

removerElem :: Int -> [Int] -> [Int]
removerElem _ [] = []
removerElem n (x:xs)
   |n == x = xs
   |otherwise = x:removerElem n xs 

-- 10. Ordene uma lista

ordenar [] = []
ordenar xs = menor xs:ordenar (removerElem (menor xs) xs)

-- 11. Insira e ordene um valor em uma lista

ins :: Int -> [Int] -> [Int]
ins x [] = [x]
ins x xs = ordenar ([x]++xs)

-- 12. Retorne o Nesimo valor de uma lista

enesimo :: Int -> [Int] -> Int 
enesimo _ [] = -1
enesimo n (x:xs)
   |n == 1 = x
   |otherwise = enesimo (n-1) xs

-- 13. crie uma lista de n elementos com apenas m elementos
repetir :: Int -> Int -> [Int]
repetir 0 _ = []
repetir x y = y:repetir (x-1) y

-- 14. Converta Int em String
-- Não aprendi

-- 15. Converta String em Int
-- Não aprendi

-- 16. Converta Binary para Int
-- Não aprendi

-- 17. Int para Binary
-- Não aprendi

-- 18. String para lowercase String
-- Não aprendi

main :: IO()
main = do
   putStrLn "Rodando."