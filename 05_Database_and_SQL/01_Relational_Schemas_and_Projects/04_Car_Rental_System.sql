-- =====================================================================
-- Database Project 4: Car Rental Management System (Course 17)
-- Concepts: Vehicle Fleet Tracking, Rental Contracts, Return Inspections
-- =====================================================================

CREATE DATABASE CarRentalDB;
GO
USE CarRentalDB;
GO

-- 1. Customers
CREATE TABLE Customers (
    CustomerID INT IDENTITY(1, 1) PRIMARY KEY,
    FirstName NVARCHAR(50) NOT NULL,
    LastName NVARCHAR(50) NOT NULL,
    DriverLicenseNumber NVARCHAR(30) NOT NULL UNIQUE,
    PhoneNumber NVARCHAR(20) NOT NULL,
    Email NVARCHAR(100) NULL
);

-- 2. Vehicle Categories
CREATE TABLE VehicleCategories (
    CategoryID INT IDENTITY(1, 1) PRIMARY KEY,
    CategoryName NVARCHAR(50) NOT NULL UNIQUE,
    DailyRate DECIMAL(10, 2) NOT NULL CHECK (DailyRate > 0)
);

-- 3. Vehicles
CREATE TABLE Vehicles (
    VehicleID INT IDENTITY(1, 1) PRIMARY KEY,
    CategoryID INT NOT NULL,
    Make NVARCHAR(50) NOT NULL,
    Model NVARCHAR(50) NOT NULL,
    ManufactureYear SMALLINT NOT NULL CHECK (ManufactureYear BETWEEN 1980 AND 2030),
    PlateNumber NVARCHAR(20) NOT NULL UNIQUE,
    Mileage INT NOT NULL DEFAULT 0 CHECK (Mileage >= 0),
    IsAvailable BIT NOT NULL DEFAULT 1,

    CONSTRAINT FK_Vehicles_Categories FOREIGN KEY (CategoryID) REFERENCES VehicleCategories(CategoryID)
);

-- 4. Rental Bookings
CREATE TABLE Bookings (
    BookingID INT IDENTITY(1, 1) PRIMARY KEY,
    CustomerID INT NOT NULL,
    VehicleID INT NOT NULL,
    RentalStartDate DATETIME NOT NULL,
    RentalEndDate DATETIME NOT NULL,
    InitialTotalDays AS (DATEDIFF(day, RentalStartDate, RentalEndDate)),
    TotalRentalPrice DECIMAL(10, 2) NOT NULL CHECK (TotalRentalPrice >= 0),
    Status NVARCHAR(20) NOT NULL DEFAULT 'Active' CHECK (Status IN ('Active', 'Completed', 'Cancelled')),

    CONSTRAINT FK_Bookings_Customers FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID),
    CONSTRAINT FK_Bookings_Vehicles FOREIGN KEY (VehicleID) REFERENCES Vehicles(VehicleID),
    CONSTRAINT CHK_BookingDates CHECK (RentalEndDate >= RentalStartDate)
);

-- 5. Vehicle Returns & Inspection
CREATE TABLE VehicleReturns (
    ReturnID INT IDENTITY(1, 1) PRIMARY KEY,
    BookingID INT NOT NULL UNIQUE,
    ActualReturnDate DATETIME NOT NULL DEFAULT GETDATE(),
    ActualMileage INT NOT NULL,
    ConsumedMileage AS (ActualMileage - 0),
    AdditionalCharges DECIMAL(10, 2) DEFAULT 0 CHECK (AdditionalCharges >= 0),
    FinalTotalAmount DECIMAL(10, 2) NOT NULL CHECK (FinalTotalAmount >= 0),

    CONSTRAINT FK_Returns_Bookings FOREIGN KEY (BookingID) REFERENCES Bookings(BookingID)
);

CREATE NONCLUSTERED INDEX IX_Vehicles_Availability ON Vehicles(IsAvailable);
CREATE NONCLUSTERED INDEX IX_Bookings_Customer ON Bookings(CustomerID);
GO
