SELECT c.name
FROM Customer c
WHERE COALESCE(c.referee_id, 0) <> 2;
