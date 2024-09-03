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

def plot_multiple_lines(df, x_column, y_columns, sheet_name):
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
    plt.ylabel("Execution time in seconds")
    plt.title(sheet_name+f' case of different Quick sort algorithms')
    plt.grid(True)
    plt.legend()
    plt.show()

# Example usage

file_path = Path("Run times/quickSorts.ods")
sheet_name = 'Worst'
x_column = 'Input size'
y_columns = [ 'Random element as pivot', 'Median of first, middle and last element as pivot']
# y_columns = ['Merge Sort', 'Heap Sort', 'Radix Sort']

df = read_ods_to_dataframe(file_path, sheet_name)
if df is not None:
    df = select_columns(df, [x_column] + y_columns)
    plot_multiple_lines(df, x_column, y_columns, sheet_name)
