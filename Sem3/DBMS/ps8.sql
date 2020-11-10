# PL/SQL Procedures/funcitons and Triggers
 
# 1
DELIMITER //
 
CREATE PROCEDURE UpdateListItems()
BEGIN
    DECLARE order_no NUMERIC(5);
    DECLARE current_rate NUMERIC(8, 2);
    SELECT MAX(OrdNo) INTO order_no FROM ORDERS WHERE CustNo = 106;
    SELECT Rate INTO current_rate FROM ITEMS WHERE ItemNo = 3;
    INSERT INTO LINEITEMS
    VALUES (order_no, 3, 2, current_rate, 8);
END //
 
DELIMITER ;
 
# 2
DELIMITER //
 
CREATE PROCEDURE ChangeRate()
BEGIN
    DECLARE avg_rate NUMERIC(8, 2);
    DECLARE current_rate NUMERIC(8, 2);
    SELECT AVG(Price) INTO avg_rate FROM LINEITEMS WHERE ItemNo = 5;
    SELECT Rate INTO current_rate FROM ITEMS WHERE ItemNo = 5;
    UPDATE ITEMS SET Rate = GREATEST(avg_rate, current_rate) WHERE ItemNo = 5;
end //
 
DELIMITER ;
 
# 3
DELIMITER //
CREATE PROCEDURE InsertLineItems()
BEGIN
    DECLARE order_no NUMERIC(5);
    DECLARE item_no NUMERIC(5);
    DECLARE item_rate, current_rate NUMERIC(8, 2);
    DECLARE item_discount NUMERIC(4, 2);
    SELECT MAX(OrdNo) INTO order_no FROM ORDERS WHERE CustNo = 102;
    SELECT ItemNo, Rate INTO item_no, current_rate FROM ITEMS WHERE UPPER(ItemName) = 'PIII PROCESSOR';
    SELECT MIN(price) INTO item_rate FROM LINEITEMS WHERE ItemNo = item_no;
    IF current_rate > item_rate THEN
        SET item_discount = 10;
    ELSE
        SET item_discount = 0;
    END IF;
    INSERT INTO LINEITEMS
    VALUES (order_no, item_no, 2, item_rate, item_discount);
 
end //
DELIMITER ;
 
# 4
DELIMITER //
CREATE PROCEDURE MaxMissingOrderNo()
BEGIN
    DECLARE min_order_no, max_order_no NUMERIC(5);
    DECLARE x NUMERIC(5);
    DECLARE cnt NUMERIC(2);
    SELECT MIN(OrdNo) INTO min_order_no FROM ORDERS;
    SELECT MAX(OrdNo) INTO max_order_no FROM ORDERS;
    SET x = max_order_no;
    loop_label:
    LOOP
        SELECT COUNT(*) INTO cnt FROM ORDERS WHERE OrdNo = x;
        IF cnt = 0 THEN
            SELECT x;
            LEAVE loop_label;
        ELSE
            SET x = x + 1;
            ITERATE loop_label;
        END IF;
    END LOOP;
END //
DELIMITER ;
 
# 5
SELECT CustName
FROM CUSTOMERS
WHERE CustNo IN (SELECT CustNo
                 FROM ORDERS
                 WHERE OrdNo IN (SELECT OrdNo FROM ORDERS WHERE Qty * Price > 10000)
                 GROUP BY CustNo
                 HAVING COUNT(*) > 3);
 
# 6
DELIMITER //
CREATE PROCEDURE ChangeRate()
BEGIN
    DECLARE finished INTEGER DEFAULT 0;
    DECLARE item_no NUMERIC(5);
    DECLARE avg_rate, current_rate NUMERIC(8, 2);
    DECLARE itemCursor CURSOR FOR SELECT ItemNo FROM ITEMS;
    DECLARE item_count NUMERIC(2);
 
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET finished = 1;
 
    OPEN itemCursor;
 
    getItem:
    LOOP
        FETCH itemCursor INTO item_no;
        IF finished = 1 THEN
            LEAVE getItem;
        END IF;
 
        SELECT COUNT(*) INTO item_count FROM LINEITEMS WHERE ItemNo = item_no;
 
        SELECT AVG(Price) INTO avg_rate FROM LINEITEMS WHERE ItemNo = 5;
        SELECT Rate INTO current_rate FROM ITEMS WHERE ItemNo = item_no;
 
        IF item_count > 5 THEN
            UPDATE ITEMS SET Rate = Rate * 1.1;
 
        ELSEIF avg_rate > current_rate THEN
            UPDATE ITEMS SET Rate = Rate * 1.02;
 
        ELSE
            UPDATE ITEMS SET Rate = Rate * 0.97;
 
        END IF;
 
    END LOOP getItem;
    CLOSE itemCursor;
 
END//
DELIMITER ;
 
# 7
 
CREATE TABLE CUSTSUM
(
    CustNo      NUMERIC(5),
    CustName    VARCHAR(20),
    NoOfOrders  NUMERIC(2),
    RecentOrder DATE,
    TotalAmount NUMERIC(8, 2)
);
 
DELIMITER //
CREATE PROCEDURE CreateCustSum()
BEGIN
    DECLARE finished INTEGER DEFAULT 0;
    DECLARE customer_no NUMERIC(5);
    DECLARE customer_name VARCHAR(20);
    DECLARE no_of_orders_placed NUMERIC(2);
    DECLARE recent_order_date DATE;
    DECLARE total_amount NUMERIC(8, 2);
    DECLARE customer_cursor CURSOR FOR SELECT CustNo, CustName FROM CUSTOMERS;
 
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET finished = 1;
 
    OPEN customer_cursor;
 
    getCustomer:
    LOOP
        FETCH customer_cursor INTO customer_no, customer_name;
        IF finished = 1 THEN
            LEAVE getCustomer;
        END IF;
        SELECT COUNT(*), MAX(OrdDat), SUM(Qty * Price)
        INTO no_of_orders_placed, recent_order_date, total_amount
        FROM ORDERS
                 NATURAL JOIN LINEITEMS
        WHERE CustNo = customer_no;
 
        INSERT INTO CUSTSUM
        VALUES (customer_no, customer_name, no_of_orders_placed, recent_order_date, total_amount);
    END LOOP getCustomer;
    CLOSE customer_cursor;
 
END //
DELIMITER ;
 
# 8
SELECT ItemName
FROM ITEMS
WHERE ItemNo IN
      (SELECT DISTINCT ItemNo FROM ITEMS I WHERE Rate < (SELECT AVG(Price) FROM LINEITEMS WHERE I.ItemNo = ItemNo))
   OR ItemNo IN
      (SELECT DISTINCT ItemNo FROM LINEITEMS GROUP BY ItemNo HAVING SUM(Qty) < 10);
 
# 9
DELIMITER //
CREATE PROCEDURE PS8_9(IN order_no NUMERIC(5),
                       IN item_no NUMERIC(5))
BEGIN
    DECLARE item_price NUMERIC(8, 2);
    SELECT Rate INTO item_price FROM ITEMS WHERE ItemNo = item_no;
    INSERT INTO LINEITEMS
    VALUES (order_no, item_no, 1, item_price, 10);
END//
DELIMITER ;
 
# 10
DELIMITER //
CREATE FUNCTION MissingOrderNo()
    RETURNS NUMERIC(5)
    DETERMINISTIC
BEGIN
    DECLARE order_count NUMERIC(2);
    DECLARE min_order_no NUMERIC(5);
    DECLARE max_order_no NUMERIC(5);
    DECLARE x NUMERIC(5);
 
    SELECT MIN(OrdNo), MAX(OrdNo) INTO min_order_no, max_order_no FROM ORDERS;
 
    SET x = min_order_no;
 
    getOrder:
    LOOP
        IF x > max_order_no THEN
            LEAVE getOrder;
        END IF;
        SELECT COUNT(*) INTO order_count FROM ORDERS WHERE OrdNo = x;
        IF order_count = 0 THEN
            RETURN (x);
        END IF;
        SET x = x + 1;
    END LOOP getOrder;
    RETURN NULL;
END //
DELIMITER ;
 
# 11
DELIMITER //
CREATE FUNCTION ReturnCustomerName(
    order_no NUMERIC(5)
)
    RETURNS VARCHAR(20)
    DETERMINISTIC
BEGIN
    DECLARE customer_name VARCHAR(20);
    SELECT CustName
    INTO customer_name
    FROM CUSTOMERS
    WHERE CustId = (SELECT DISTINCT CustId FROM ORDERS WHERE OrdNo = order_no);
    RETURN (customer_name);
END //
DELIMITER ;
 
# 12
DELIMITER //
CREATE PROCEDURE InsertIntoLineItems(IN item_no NUMERIC(5),
                                     IN price NUMERIC(8, 2),
                                     IN quantity NUMERIC(3))
BEGIN
    DECLARE order_no NUMERIC(5);
    DECLARE current_rate NUMERIC(8, 2);
    DECLARE item_count NUMERIC(3);
    DECLARE total_amount NUMERIC(8, 2);
 
    SELECT MAX(OrdNo) INTO order_no FROM ORDERS;
 
    SELECT Rate INTO current_rate FROM ITEMS WHERE ItemNo = item_no;
 
    IF price > current_rate THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Price is greater than current rate';
    END IF;
 
    SELECT COUNT(*) INTO item_count FROM LINEITEMS WHERE OrdNo = order_no AND ItemNo = item_no;
 
    IF item_count != 0 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Item already exists in the order';
    END IF;
 
    SELECT SUM(Qty * Price) INTO total_amount FROM LINEITEMS WHERE OrdNo = order_no;
 
    IF (quantity * price) + total_amount > 50000 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Total amount exceeds 50000';
    END IF;
 
    INSERT INTO LINEITEMS
    VALUES (order_no, item_no, quantity, price, 0);
 
END //
DELIMITER ;
 
# 13
DELIMITER //
CREATE TRIGGER CheckItemCount
    BEFORE INSERT
    ON LINEITEMS
    FOR EACH ROW
BEGIN
    DECLARE row_count INT;
    SELECT COUNT(*) INTO row_count FROM LINEITEMS;
 
    IF row_count > 5 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Number of items per order is greater than 5';
    END IF;
 
END //
DELIMITER ;
 
# 14
DELIMITER //
CREATE TRIGGER CheckTime
    BEFORE UPDATE
    ON ITEMS
    FOR EACH ROW
BEGIN
    DECLARE current__time TIME;
    IF CURRENT_TIME() < STR_TO_DATE('9 am', '%I %p') OR CURRENT_TIME() > STR_TO_DATE('9 pm', '%I %p') THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Changes cannot be made before 9 am and after 9 pm';
    END IF;
 
END //
DELIMITER ;
 
# 15
DELIMITER //
CREATE TRIGGER CheckRateChange
    BEFORE UPDATE
    ON ITEMS
    FOR EACH ROW
BEGIN
    DECLARE diff_rate NUMERIC(4, 2);
    SET diff_rate = NEW.Rate - OLD.Rate;
    IF diff_rate > OLD.Rate * 0.25 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Invalid rate amount. Change is too big';
    END IF;
END //
DELIMITER ;
 
# 16
DELIMITER //
CREATE PROCEDURE PS8_16()
BEGIN
    DECLARE order_no NUMERIC(5);
    DECLARE order_date DATE;
    DECLARE customer_no NUMERIC(5);
    DECLARE ship_date DATE;
    DECLARE address1 VARCHAR(50);
    DECLARE address2 VARCHAR((50);
    DECLARE city VARCHAR(30);
    DECLARE state VARCHAR(30);
    DECLARE pincode VARCHAR(10);
    DECLARE phone VARCHAR(30);
    DECLARE price NUMERIC(8, 2);
    SELECT MAX(OrdNo) + 1
    INTO order_no
    FROM ORDERS;
    SET order_date := SUBDATE(CURRENT_DATE, 1);
    SET customer_no := 103;
    SET ship_date := ADDDATE(@order_date, 15);
    SELECT Address1, Address2, City, State, Pincode, Phone
    INTO address1, address2, city, state, pincode, phone
    FROM CUSTOMERS;
 
    INSERT INTO ORDERS
    VALUES (order_no, @order_date, ship_date, customer_no, address1, address2, city, state, pincode, phone);
 
    SELECT MIN(Price) INTO price FROM LINEITEMS WHERE ItemNo = 4;
 
    INSERT INTO LINEITEMS
    VALUES (order_no, 4, 2, price, 0);
 
END//
DELIMITER ;
 
# 17
DELIMITER //
CREATE PROCEDURE DisplayItems()
BEGIN
    DECLARE finished INTEGER DEFAULT 0;
    DECLARE item_name VARCHAR(20);
    DECLARE item_no NUMERIC(5);
    DECLARE item_count NUMERIC(2);
    DECLARE item_cursor CURSOR FOR SELECT ItemNo, SUM(Qty) FROM LINEITEMS GROUP BY ItemNo;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET finished = 1;
 
    OPEN item_cursor;
    item_loop:
    LOOP
        FETCH item_cursor INTO item_no, item_count;
        IF finished = 1 THEN
            LEAVE item_loop;
        END IF;
        IF item_count != 0 THEN
            SELECT ItemName INTO item_name FROM ITEMS WHERE ItemNo = item_no;
            SELECT item_name AS ItemName, item_count AS ItemCount;
        END IF;
    END LOOP;
 
    CLOSE item_cursor;
END //
DELIMITER ;
 
# 18
DELIMITER //
CREATE PROCEDURE PS8_18()
BEGIN
    DECLARE item_rate NUMERIC(8, 2);
 
    SELECT Rate INTO item_rate FROM ITEMS WHERE ItemNo = 4;
 
    INSERT INTO LINEITEMS
    VALUES (1003, 4, 1, item_rate, 5);
 
END //
DELIMITER ;
 
# 19
DELIMITER //
CREATE PROCEDURE PS8_19()
BEGIN
    DECLARE item_rate NUMERIC(8, 2);
    DECLARE item_count NUMERIC(2);
    DECLARE total_amount NUMERIC(8, 2);
    DECLARE order_date DATE;
 
    SELECT COUNT(*) INTO item_count FROM LINEITEMS WHERE ItemNo = 4 AND OrdNo = 1003;
    IF item_count >= 1 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Item 4 alredy exists for order 1003';
    END IF;
 
    SELECT SUM(Qty * Price) INTO total_amount FROM LINEITEMS WHERE OrdNo = 1003;
    IF total_amount > 30000 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Total amount of order is crossing 30000';
    END IF;
 
    SELECT OrdDate INTO order_date FROM ORDERS WHERE OrdNo = 1003;
    IF DATEDIFF(CURRENT_DATE, order_date) > 4 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Order was placed before 4 days';
    END IF;
 
    SELECT Rate INTO item_rate FROM ITEMS WHERE ItemNo = 4;
 
    INSERT INTO LINEITEMS
    VALUES (1003, 4, 1, item_rate, 5);
 
END //
DELIMITER ;
 
# 20
DELIMITER //
CREATE PROCEDURE DisplayAmount()
BEGIN
    DECLARE finished INTEGER DEFAULT 0;
    DECLARE cust_name VARCHAR(20);
    DECLARE cust_no NUMERIC(5);
    DECLARE cust_cursor CURSOR FOR SELECT CustNo, CustName FROM CUSTOMERS LIMIT 5;
    DECLARE amount NUMERIC(8, 2);
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET finished = 1;
 
    OPEN cust_cursor;
 
    cust_loop:
    LOOP
        FETCH cust_cursor INTO cust_no, cust_name;
        IF finished = 1 THEN
            LEAVE cust_loop;
        END IF;
 
        SELECT SUM(Qty * Price) INTO amount FROM LINEITEMS WHERE OrdNo IN (SELECT OrdNo FROM ORDERS WHERE CustNo = cust_no);
 
        SELECT cust_name AS CustomerName, amount AS TotalAmount;
    END LOOP;
 
    CLOSE cust_cursor;
 
END //
DELIMITER ;
 
# 21
DELIMITER //
CREATE PROCEDURE PS8_20()
BEGIN
   DECLARE finished INTEGER DEFAULT 0;
   DECLARE item_no NUMERIC(5);
   DECLARE item_cursor CURSOR FOR SELECT ItemNo, Rate FROM ITEMS;
   DECLARE CONTINUE HANDLER FOR NOT FOUND SET finished = 1;
   DECLARE item_count NUMERIC(2);
   DECLARE item_qty NUMERIC(2);
   DECLARE item_rate NUMERIC(8, 2);
   OPEN item_cursor;
 
    item_loop:
    LOOP
        FETCH item_cursor INTO item_no, item_rate;
        IF finished = 1 THEN
            LEAVE item_loop;
        END IF;
 
        SELECT COUNT(*), SUM(Qty) INTO item_count, item_qty FROM LINEITEMS WHERE ItemNo = item_no;
 
        IF item_count > 5 OR item_qty > 25 THEN
            UPDATE ITEMS SET Rate = 1.1 * Rate WHERE ItemNo = item_no;
        ELSE
            SELECT COUNT(*) INTO item_count FROM LINEITEMS WHERE ItemNo = item_no AND Price > item_rate;
            IF item_count > 0 THEN
                 UPDATE ITEMS SET Rate = 1.05 * Rate WHERE ItemNo = item_no;
            END IF;
        END IF;
 
    END LOOP;
 
   CLOSE item_cursor;
END //
DELIMITER ;
 
# 22
DELIMITER //
CREATE TRIGGER PreventIncrease
    BEFORE UPDATE
    ON LINEITEMS
    FOR EACH ROW
BEGIN
    IF NEW.Price != OLD.Price THEN;
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Not allowed to change price of items';
    END IF;
END //
DELIMITER ;
 
# 23
DELIMITER //
CREATE TRIGGER CheckTime
    BEFORE UPDATE
    ON ORDERS
    FOR EACH ROW
BEGIN
    DECLARE current__time TIME;
    IF CURRENT_TIME() < STR_TO_DATE('9 am', '%I %p') OR CURRENT_TIME() > STR_TO_DATE('9 pm', '%I %p') THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Changes cannot be made before 9 am and after 9 pm';
    END IF;
 
END //
DELIMITER ;
 
# 24
DELIMITER //
CREATE FUNCTION NextOrderno(
    order_no NUMERIC(5)
)
    RETURNS NUMERIC(5)
    DETERMINISTIC
BEGIN
    DECLARE order_count NUMERIC(2);
    DECLARE max_order_no NUMERIC(5);
    DECLARE x NUMERIC(5);
    SET x = order_no + 1;
    getorder: LOOP
        IF x > max_order_no THEN
            LEAVE getOrder;
        END IF;
        SELECT COUNT(*) INTO order_count FROM ORDERS WHERE OrdNo = x;
        IF order_count != 0 THEN
            RETURN (x);
        END IF;
        SET x = x + 1;
    END LOOP;
    RETURN NULL;
END //
DELIMITER ;
 
# 25
DELIMITER //
CREATE FUNCTION MissingOrderNo()
    RETURNS NUMERIC(5)
    DETERMINISTIC
BEGIN
    DECLARE order_count NUMERIC(2);
    DECLARE min_order_no NUMERIC(5);
    DECLARE max_order_no NUMERIC(5);
    DECLARE x NUMERIC(5);
 
    SELECT MIN(OrdNo), MAX(OrdNo) INTO min_order_no, max_order_no FROM ORDERS;
 
    SET x = min_order_no;
 
    getOrder:
    LOOP
        IF x > max_order_no THEN
            LEAVE getOrder;
        END IF;
        SELECT COUNT(*) INTO order_count FROM ORDERS WHERE OrdNo = x;
        IF order_count = 0 THEN
            RETURN (x);
        END IF;
        SET x = x + 1;
    END LOOP getOrder;
    RETURN NULL;
END //
DELIMITER ;