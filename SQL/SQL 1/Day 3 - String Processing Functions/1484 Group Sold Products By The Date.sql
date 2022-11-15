-- Link: https://leetcode.com/problems/group-sold-products-by-the-date/?envType=study-plan&id=sql-i

select sell_date, count( DISTINCT product ) as num_sold ,
    
    GROUP_CONCAT( DISTINCT product order by product ASC separator ',' ) as products
    
        FROM Activities GROUP BY sell_date order by sell_date ASC;