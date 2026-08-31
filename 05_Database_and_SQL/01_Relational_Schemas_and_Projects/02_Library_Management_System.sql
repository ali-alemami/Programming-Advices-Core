-- =====================================================================
-- Database Project 2: Simple Library Management System (Course 17)
-- Concepts: Multi-Table Relationships, Borrowing Transactions, Fines, Views
-- =====================================================================

CREATE DATABASE LibraryDB;
GO
USE LibraryDB;
GO

-- 1. Authors
CREATE TABLE Authors (
    AuthorID INT IDENTITY(1, 1) PRIMARY KEY,
    FullName NVARCHAR(100) NOT NULL,
    Bio NVARCHAR(MAX) NULL,
    Nationality NVARCHAR(50) NULL
);

-- 2. Categories
CREATE TABLE Categories (
    CategoryID INT IDENTITY(1, 1) PRIMARY KEY,
    CategoryName NVARCHAR(50) NOT NULL UNIQUE
);

-- 3. Books
CREATE TABLE Books (
    BookID INT IDENTITY(1, 1) PRIMARY KEY,
    Title NVARCHAR(200) NOT NULL,
    ISBN NVARCHAR(20) NOT NULL UNIQUE,
    PublicationYear SMALLINT NULL,
    CategoryID INT NOT NULL,
    TotalCopies INT NOT NULL DEFAULT 1 CHECK (TotalCopies >= 0),
    AvailableCopies INT NOT NULL DEFAULT 1 CHECK (AvailableCopies >= 0),

    CONSTRAINT FK_Books_Categories FOREIGN KEY (CategoryID) REFERENCES Categories(CategoryID),
    CONSTRAINT CHK_Copies CHECK (AvailableCopies <= TotalCopies)
);

-- 4. Book Authors (Many-to-Many Bridge)
CREATE TABLE BookAuthors (
    BookID INT NOT NULL,
    AuthorID INT NOT NULL,
    PRIMARY KEY (BookID, AuthorID),
    CONSTRAINT FK_BA_Books FOREIGN KEY (BookID) REFERENCES Books(BookID) ON DELETE CASCADE,
    CONSTRAINT FK_BA_Authors FOREIGN KEY (AuthorID) REFERENCES Authors(AuthorID) ON DELETE CASCADE
);

-- 5. Members
CREATE TABLE Members (
    MemberID INT IDENTITY(1, 1) PRIMARY KEY,
    FullName NVARCHAR(100) NOT NULL,
    Email NVARCHAR(100) NOT NULL UNIQUE,
    PhoneNumber NVARCHAR(20) NOT NULL,
    MembershipDate DATE DEFAULT GETDATE(),
    IsActive BIT NOT NULL DEFAULT 1
);

-- 6. Borrowing Records
CREATE TABLE BorrowingRecords (
    BorrowID INT IDENTITY(1, 1) PRIMARY KEY,
    BookID INT NOT NULL,
    MemberID INT NOT NULL,
    BorrowDate DATE NOT NULL DEFAULT GETDATE(),
    DueDate DATE NOT NULL,
    ActualReturnDate DATE NULL,
    Status NVARCHAR(20) NOT NULL DEFAULT 'Borrowed' CHECK (Status IN ('Borrowed', 'Returned', 'Overdue', 'Lost')),

    CONSTRAINT FK_Borrowing_Books FOREIGN KEY (BookID) REFERENCES Books(BookID),
    CONSTRAINT FK_Borrowing_Members FOREIGN KEY (MemberID) REFERENCES Members(MemberID),
    CONSTRAINT CHK_DueAfterBorrow CHECK (DueDate >= BorrowDate)
);

-- 7. Fines
CREATE TABLE Fines (
    FineID INT IDENTITY(1, 1) PRIMARY KEY,
    BorrowID INT NOT NULL UNIQUE,
    FineAmount DECIMAL(6, 2) NOT NULL CHECK (FineAmount >= 0),
    IsPaid BIT NOT NULL DEFAULT 0,
    PaidDate DATE NULL,

    CONSTRAINT FK_Fines_Borrowing FOREIGN KEY (BorrowID) REFERENCES BorrowingRecords(BorrowID)
);

-- Performance Indexing
CREATE NONCLUSTERED INDEX IX_Borrowing_Member ON BorrowingRecords(MemberID);
CREATE NONCLUSTERED INDEX IX_Borrowing_Book ON BorrowingRecords(BookID);
GO
