-- =====================================================================
-- Course 17: Self-Referential Queries & Hierarchy Models (Problems 51 - 54)
-- Database: EmployeesDB
-- Topics: Recursive & Self Joins, ISNULL / COALESCE, Left Join Fallbacks
-- =====================================================================

USE EmployeesDB;
GO

-- Schema definition for Employees hierarchy
IF OBJECT_ID('Employees', 'U') IS NULL
BEGIN
    CREATE TABLE Employees (
        EmployeeID INT IDENTITY(1, 1) PRIMARY KEY,
        FullName NVARCHAR(100) NOT NULL,
        Title NVARCHAR(50) NOT NULL,
        ManagerID INT NULL,
        Salary DECIMAL(10, 2) NOT NULL,
        
        CONSTRAINT FK_Employees_Manager FOREIGN KEY (ManagerID) 
            REFERENCES Employees(EmployeeID)
    );
END
GO

-- Problem 51: Get all employees that have a manager along with Manager's name
SELECT 
    E.EmployeeID,
    E.FullName AS EmployeeName,
    E.Title AS EmployeeTitle,
    M.FullName AS ManagerName,
    M.Title AS ManagerTitle
FROM Employees E
INNER JOIN Employees M ON E.ManagerID = M.EmployeeID;

-- Problem 52: Get all employees whether they have a manager or not (NULL if no manager)
SELECT 
    E.EmployeeID,
    E.FullName AS EmployeeName,
    E.Title AS EmployeeTitle,
    M.FullName AS ManagerName
FROM Employees E
LEFT JOIN Employees M ON E.ManagerID = M.EmployeeID;

-- Problem 53: If employee has no manager, show the employee's own name as manager
SELECT 
    E.EmployeeID,
    E.FullName AS EmployeeName,
    E.Title AS EmployeeTitle,
    COALESCE(M.FullName, E.FullName) AS ManagerName
FROM Employees E
LEFT JOIN Employees M ON E.ManagerID = M.EmployeeID;

-- Problem 54: Get all employees managed by 'Mohammed'
SELECT 
    E.EmployeeID,
    E.FullName AS EmployeeName,
    E.Title AS EmployeeTitle,
    M.FullName AS ManagerName
FROM Employees E
INNER JOIN Employees M ON E.ManagerID = M.EmployeeID
WHERE M.FullName LIKE '%Mohammed%';
GO
