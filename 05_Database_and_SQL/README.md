# Module 05: Relational Database Architecture & SQL Mastery

Comprehensive production schemas, analytical SQL query suites, normalization guides, and enterprise relational models designed across **Course 15 (SQL Concepts & Practice)** and **Course 17 (SQL Projects & Analytical Problem Solving)**.

---

## 📁 Repository Structure

```
05_Database_and_SQL/
├── 01_Relational_Schemas_and_Projects/
│   ├── 01_Clinic_Management_System.sql    # Patients, Doctors, Appointments, Medical Records
│   ├── 02_Library_Management_System.sql   # Multi-author books, Borrows, Fines, Categories
│   ├── 03_Karate_Club_System.sql          # Belt ranks, Subscriptions, Belt tests, Instructors
│   ├── 04_Car_Rental_System.sql           # Vehicle fleet, Daily rates, Rental contracts & returns
│   └── 05_Online_Store_System.sql         # Nested categories, Order items, Stocks, Payments
├── 02_SQL_Practices_and_Queries/
│   ├── 01_Vehicle_Database_50_Queries.sql # 50 Analytical SQL problems on VehicleMakesDB
│   └── 02_Self_Referential_Queries_and_Hierarchies.sql # Self-joins & Employee-Manager hierarchies
└── 03_Concepts_and_Normalization/
    └── Database_Design_and_Normalization_Guide.md # 1NF -> BCNF, Indexes, Constraints
```

---

## 🚀 Key Database Engineering Highlights

1. **Production-Grade DDL**: Strict referential integrity, cascading rules, check constraints (`CHECK`), identity keys, and non-clustered performance indexes.
2. **Analytical Query Patterns**: Window functions (`SUM() OVER()`), dynamic aggregations (`HAVING`), pattern matching (`LIKE`), scalar subqueries, and random sorting (`NEWID()`).
3. **Enterprise Hierarchy Modeling**: Self-referential joins (`INNER` / `LEFT JOIN`) and fallback handling (`COALESCE` / `CASE`) for organizational trees.
