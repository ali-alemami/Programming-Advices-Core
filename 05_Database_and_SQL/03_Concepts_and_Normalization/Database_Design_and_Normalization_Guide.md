# Database Architecture & Normalization Mastery Guide

Comprehensive reference covering relational theory, normalization rules (1NF to BCNF), constraint enforcement, and query optimization patterns practiced throughout **Course 15 & Course 17**.

---

## 1. Relational Database Normalization

| Normal Form | Rule Requirement | Violation Scenario | Resolution |
| :--- | :--- | :--- | :--- |
| **1NF (First Normal Form)** | Atomic values per column, unique rows (Primary Key), no repeating groups/arrays. | Storing comma-separated phone numbers: `"079123, 078456"` in a single column. | Split into separate rows or create a dedicated `ContactPhones` table. |
| **2NF (Second Normal Form)** | Must be in 1NF **AND** no partial dependency (all non-key attributes depend on the **entire** composite primary key). | In a composite table `(StudentID, CourseID)` with `CourseFee`. `CourseFee` depends only on `CourseID`, not `StudentID`. | Extract `Courses (CourseID, CourseName, CourseFee)` to its own table. |
| **3NF (Third Normal Form)** | Must be in 2NF **AND** no transitive dependency (non-key columns must not depend on other non-key columns). | `(OrderID, CustomerID, CustomerCity, CustomerPostalCode)`. `CustomerCity` depends on `CustomerID`, not `OrderID`. | Extract `Customers (CustomerID, City, PostalCode)` to separate table. |
| **BCNF (Boyce-Codd)** | Every determinant must be a candidate key. Handles edge-case anomalies in composite candidate keys. | Multiple overlapping candidate keys with functional dependencies on non-candidate keys. | Decompose into distinct relations where the left side of every dependency is a superkey. |

---

## 2. Referential Integrity & Cascading Actions

```sql
CONSTRAINT FK_Child_Parent 
    FOREIGN KEY (ParentID) REFERENCES ParentTable(ParentID)
    ON DELETE CASCADE       -- Automatically delete child rows when parent is deleted
    ON UPDATE CASCADE       -- Automatically update foreign keys when parent ID changes
```

* **`NO ACTION / RESTRICT`** (Default): Rejects parent deletion if dependent child records exist.
* **`SET NULL`**: Sets the foreign key column to `NULL` when the parent record is deleted.
* **`CASCADE`**: Propagates changes automatically throughout all child entities.

---

## 3. Indexing & Query Performance Optimization

```sql
-- Non-clustered index on high-cardinality foreign keys and search columns
CREATE NONCLUSTERED INDEX IX_Appointments_PatientID 
    ON Appointments(PatientID) 
    INCLUDE (AppointmentDateTime, Status);
```

* **Clustered Index**: Physical ordering of data on disk (automatically created on the Primary Key). Only **one** per table.
* **Non-Clustered Index**: B-Tree structure storing indexed column values with row locators (pointers). Up to 999 per table.
* **Covering Index (`INCLUDE`)**: Includes non-key columns in leaf nodes to satisfy queries entirely from the index without index lookups.
