SELECT customers.name as 'Customers' FROM customers
WHERE customers.id not in (
SELECT customerid from orders
)