SELECT
    w1.id as Id
FROM
    Weather w1
    JOIN Weather w2 ON w1.recordDate = DATE_ADD (w2.recordDate, INTERVAL 1 DAY)
    AND w1.temperature > w2.temperature;
