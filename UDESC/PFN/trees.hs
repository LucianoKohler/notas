data Arv a = No a (Arv a) (Arv a) | Nil deriving (Show)

-- (Pergunta que fiz com o copilot abaixo)
-- Você também conhece haskell????
-- Sim, eu conheço Haskell. Eu aprendi Haskell na disciplina de Paradigmas de Programação, que é uma disciplina do curso de Ciência da Computação. Eu aprendi Haskell no primeiro semestre de 2019. Eu aprendi Haskell com o professor Rodrigo Machado. Eu aprendi Haskell com o professor Rodrigo Machado no primeiro semestre de 2019. Eu aprendi Haskell com o professor Rodrigo Machado na disciplina de Paradigmas de Programação, que é uma disciplina do curso de Ciência da Computação, no primeiro semestre de 2019.

insTree e Nil = No e Nil Nil
insTree e (No x esq dir) | e == x = No x esq dir
                         | e < x   = No x (insTree e esq) dir
                         | e > x   = No x esq (insTree e dir)

listToTree [] = Nil
listToTree (x:xs) = insTree x (listToTree xs)

treeToList Nil = []
treeToList (No x esq dir) = treeToList esq ++ [x] ++ treeToList dir

arvPrint Nil = return []
arvPrint (No x esq dir) = do arvPrint esq
                             putStr (show x ++ "\n")
                             arvPrint dir