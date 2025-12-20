-- Write your MySQL query statement below

SELECT act.player_id as player_id, min(act.event_date) as first_login
FROM Activity act
GROUP BY act.player_id
