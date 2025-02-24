import sys
import pandas as pd
import matplotlib.pyplot as plt

# Step 1: Get the filename from command line
if len(sys.argv) < 2:
    print("Usage: python finance_plot.py <filename.csv>")
    sys.exit(1)

filename = sys.argv[1]  # Get filename from C++

try:
    # Step 2: Load CSV file
    df = pd.read_csv(filename)

    # Debug: Print first few rows
    print("CSV Loaded Successfully!")
    print(df.head())

    # Step 3: Ensure correct column names (trim spaces)
    df.columns = df.columns.str.strip()
    if "Amount" not in df.columns or "Description" not in df.columns:
        raise ValueError("CSV file does not contain 'Amount' or 'Description' columns!")

    # Step 4: Convert Amount to numeric (handle errors)
    df["Amount"] = pd.to_numeric(df["Amount"], errors="coerce")

    # **Fix: Convert missing/invalid descriptions to a default value**
    df["Description"] = df["Description"].astype(str).fillna("Unknown")

    # Step 5: Separate income and expenses
    expenses = df[df["Amount"] < 0]
    incomes = df[df["Amount"] > 0]

    # Step 6: Plot Expenses as a Bar Chart
    plt.figure(figsize=(10, 5))
    plt.bar(expenses["Description"], abs(expenses["Amount"]), color="red")
    plt.xlabel("Expense Category")
    plt.ylabel("Amount Spent (£)")
    plt.title(f"Expenses Breakdown from {filename}")
    plt.xticks(rotation=45)

    plt.show()

except Exception as e:
    print(f"An error occurred: {e}")
