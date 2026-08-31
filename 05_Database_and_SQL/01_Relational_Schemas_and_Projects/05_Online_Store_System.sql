-- =====================================================================
-- Database Project 5: Online Store & E-Commerce System (Course 17)
-- Concepts: Order Processing, Order Items, Stock Management, Shipping
-- =====================================================================

CREATE DATABASE OnlineStoreDB;
GO
USE OnlineStoreDB;
GO

-- 1. Customers
CREATE TABLE Customers (
    CustomerID INT IDENTITY(1, 1) PRIMARY KEY,
    FirstName NVARCHAR(50) NOT NULL,
    LastName NVARCHAR(50) NOT NULL,
    Email NVARCHAR(100) NOT NULL UNIQUE,
    PasswordHash NVARCHAR(256) NOT NULL,
    PhoneNumber NVARCHAR(20) NOT NULL,
    RegistrationDate DATETIME DEFAULT GETDATE()
);

-- 2. Categories
CREATE TABLE Categories (
    CategoryID INT IDENTITY(1, 1) PRIMARY KEY,
    CategoryName NVARCHAR(100) NOT NULL UNIQUE,
    ParentCategoryID INT NULL,

    CONSTRAINT FK_Categories_Parent FOREIGN KEY (ParentCategoryID) REFERENCES Categories(CategoryID)
);

-- 3. Products
CREATE TABLE Products (
    ProductID INT IDENTITY(1, 1) PRIMARY KEY,
    CategoryID INT NOT NULL,
    ProductName NVARCHAR(150) NOT NULL,
    Description NVARCHAR(MAX) NULL,
    UnitPrice DECIMAL(10, 2) NOT NULL CHECK (UnitPrice >= 0),
    UnitsInStock INT NOT NULL DEFAULT 0 CHECK (UnitsInStock >= 0),
    IsActive BIT NOT NULL DEFAULT 1,

    CONSTRAINT FK_Products_Categories FOREIGN KEY (CategoryID) REFERENCES Categories(CategoryID)
);

-- 4. Orders
CREATE TABLE Orders (
    OrderID INT IDENTITY(1, 1) PRIMARY KEY,
    CustomerID INT NOT NULL,
    OrderDate DATETIME DEFAULT GETDATE(),
    TotalAmount DECIMAL(12, 2) NOT NULL DEFAULT 0 CHECK (TotalAmount >= 0),
    OrderStatus NVARCHAR(30) NOT NULL DEFAULT 'Pending' 
        CHECK (OrderStatus IN ('Pending', 'Processing', 'Shipped', 'Delivered', 'Cancelled')),
    ShippingAddress NVARCHAR(300) NOT NULL,

    CONSTRAINT FK_Orders_Customers FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID)
);

-- 5. Order Details (Order Items)
CREATE TABLE OrderDetails (
    OrderDetailID INT IDENTITY(1, 1) PRIMARY KEY,
    OrderID INT NOT NULL,
    ProductID INT NOT NULL,
    Quantity INT NOT NULL CHECK (Quantity > 0),
    UnitPriceAtOrder DECIMAL(10, 2) NOT NULL CHECK (UnitPriceAtOrder >= 0),
    LineTotal AS (Quantity * UnitPriceAtOrder),

    CONSTRAINT FK_OrderDetails_Orders FOREIGN KEY (OrderID) REFERENCES Orders(OrderID) ON DELETE CASCADE,
    CONSTRAINT FK_OrderDetails_Products FOREIGN KEY (ProductID) REFERENCES Products(ProductID)
);

-- 6. Payments
CREATE TABLE Payments (
    PaymentID INT IDENTITY(1, 1) PRIMARY KEY,
    OrderID INT NOT NULL UNIQUE,
    PaymentDate DATETIME DEFAULT GETDATE(),
    AmountPaid DECIMAL(12, 2) NOT NULL CHECK (AmountPaid >= 0),
    PaymentMethod NVARCHAR(50) NOT NULL CHECK (PaymentMethod IN ('CreditCard', 'PayPal', 'CashOnDelivery')),

    CONSTRAINT FK_Payments_Orders FOREIGN KEY (OrderID) REFERENCES Orders(OrderID)
);
GO
