SELECT DISTINCT product_id,
       CASE 
           WHEN (
               SELECT new_price
               FROM products p2
               WHERE p2.product_id = p1.product_id
                 AND p2.change_date <= '2019-08-16'
               ORDER BY p2.change_date DESC
               LIMIT 1
           ) IS NULL
           THEN 10
           ELSE (
               SELECT new_price
               FROM products p2
               WHERE p2.product_id = p1.product_id
                 AND p2.change_date <= '2019-08-16'
               ORDER BY p2.change_date DESC
               LIMIT 1
           )
       END AS price
FROM products p1;