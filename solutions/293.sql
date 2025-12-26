-- Write your MySQL query statement below
SELECT o.customer_number
FROM Orders o
GROUP BY o.customer_number
ORDER BY COUNT(o.order_number) DESC
LIMIT 1;
