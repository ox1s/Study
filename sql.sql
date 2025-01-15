select name,
    age
from users
where age >= 18;
-------------------------
INSERT INTO participants(name, age, attending)
VALUES ('Palina', 23, true);
SELECT *
FROM participants;
---------------------------
-- you will be given a table 'kata' with columns 'id', 'base', and 'factor'. 
-- return the 'id' and your result in a column named 'res'.
SELECT id,
    bool (base % factor = 0) AS res
FROM kata;
SELECT n,
    m,
    CASE
        WHEN n < 0
        OR m < 0 THEN 0
        ELSE n * m
    END AS res
FROM paperwork;
-- You will be given a table: "opposite", with a column: "number". Return a table with a column: "res".
select number *(-1) as res
from opposite;
-- # write your SQL statement here: you are given a table 'multiplication' with column 'number', return a table with column 'number' and your result in a column named 'res'.
select number,
    case
        when number %2 = 0 then number * 8
        else number * 9
    end as res
from multiplication;
-- you will be given a table, goals, with columns la_liga_goals, copa_del_rey_goals, and champions_league_goals. Return a table with a column, res.
select la_liga_goals + copa_del_rey_goals + champions_league_goals as res
from goals;
-- # write your SQL statement here: you are given a table 'disemvowel' with column 'str', return a table with column 'str' and your result in a column named 'res'.
SELECT str,
    REGEXP_REPLACE(str, '[aeiou]', '', 'gi') AS res
FROM disemvowel;
-- # write your SQL statement here: you are given a table 'booltoword' with column 'bool', return a table with column 'bool' and your result in a column named 'res'.
SELECT bool,
    CASE
        WHEN bool = true THEN 'Yes'
        ELSE 'No'
    END AS res
FROM booltoword;

-- # write your SQL statement here: you are given a table 'love' with columns 'flower1' and 'flower2', return a table with columns ('flower1' and 'flower2') and your result in a column named 'res'.
SELECT flower1, 
       flower2, 
       flower1 % 2 != flower2 % 2 AS res
FROM love;

--# write your statement here: you will be given a table 'moves' with columns 'position' and 'roll'. return a table with a column 'res'. #--
SELECT position+roll*2 AS res
FROM moves;