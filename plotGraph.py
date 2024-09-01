import pandas as pd
from pathlib import Path
import matplotlib.pyplot as plt

def read_ods_to_dataframe(file_path, sheet_name):
    try:
        # Read the ODS file into a DataFrame
        df = pd.read_excel(file_path, sheet_name=sheet_name, engine='odf')
        return df
    except Exception as e:
        print(f"Error reading the ODS file: {e}")
        return None

def select_columns(df, columns):
    try:
        df = df[columns]
        return df
    except KeyError as e:
        print(f"Column selection error: {e}")
        return None

def plot_multiple_lines(df, x_column, y_columns):
    if x_column not in df.columns:
        print(f"Error: Column {x_column} not found in the DataFrame.")
        return

    plt.figure(figsize=(10, 6))

    for y_column in y_columns:
        if y_column not in df.columns:
            print(f"Error: Column {y_column} not found in the DataFrame.")
            continue
        
        x = df[x_column]
        y = df[y_column]
        plt.plot(x, y, marker='o', linestyle='-', label=y_column)

    plt.xlabel(x_column)
    plt.ylabel("Values")
    plt.title(f'Multiple Lines: {", ".join(y_columns)} vs {x_column}')
    plt.grid(True)
    plt.legend()
    plt.show()

# Example usage

file_path = Path("Run times/allSorts.ods")
sheet_name = 'Average'
x_column = 'Input size'
y_columns = ['Bubble Sort', 'Insertion Sort', 'Merge Sort', 'Quick Sort', 'Heap Sort', 'Radix Sort']

df = read_ods_to_dataframe(file_path, sheet_name)
if df is not None:
    df = select_columns(df, [x_column] + y_columns)
    plot_multiple_lines(df, x_column, y_columns)
