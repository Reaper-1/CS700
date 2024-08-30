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

def plot_from_dataframe(df, x_column, y_column):
    if x_column not in df.columns or y_column not in df.columns:
        print(f"Error: Columns {x_column} and/or {y_column} not found in the DataFrame.")
        return

    x = df[x_column]
    y = df[y_column]
    
    plt.figure(figsize=(10, 6))
    plt.plot(x, y, marker='o', linestyle='-', color='b')
    plt.xlabel(x_column)
    plt.ylabel(y_column)
    plt.title(f'{y_column} vs {x_column}')
    plt.grid(True)
    plt.show()

# Example usage

file_path = Path("CS700/Assignment 1/Run times/bubbleRandom.ods")
sheet_name = 'Sheet1'
desired_columns = ['Input size', 'Bubble sort']

df = read_ods_to_dataframe(file_path, sheet_name)
if df is not None:
    df = select_columns(df, desired_columns)
    plot_from_dataframe(df, desired_columns[0], desired_columns[1])
