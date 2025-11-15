import pandas as pd
import matplotlib.pyplot as plt

try:
    data = pd.read_csv('results.csv')
    
    total_points = data['Points']
    calculated_area = data['Area']
    error = data['Error']
    
    real_area = 0.944517
    
    plt.figure(figsize=(12, 7))
    plt.plot(total_points, calculated_area, marker='.', linestyle='-', markersize=4, label='Monte Carlo Estimated Area')
    plt.axhline(y=real_area, color='r', linestyle='--', label=f'Analytical Area = {real_area}')
    plt.title('Convergence of Area Estimation')
    plt.xlabel('Number of Sample Points')
    plt.ylabel('Estimated Area')
    plt.grid(True, which='both', linestyle='--', linewidth=0.5)
    plt.legend()
    plt.tight_layout()
    
    area_plot_filename = 'area_convergence.png'
    plt.savefig(area_plot_filename)
    print(f"Saved area convergence plot to '{area_plot_filename}'")
    
    plt.figure(figsize=(12, 7))
    plt.plot(total_points, error, marker='.', linestyle='-', markersize=4, color='g', label='Estimation Error')
    plt.axhline(y=0, color='r', linestyle='--', label='Zero Error')
    plt.title('Convergence of Estimation Error')
    plt.xlabel('Number of Sample Points')
    plt.ylabel('Error (Estimated - Analytical)')
    plt.grid(True, which='both', linestyle='--', linewidth=0.5)
    plt.legend()
    plt.tight_layout()
    
    error_plot_filename = 'error_convergence.png'
    plt.savefig(error_plot_filename)
    print(f"Saved error convergence plot to '{error_plot_filename}'")

    print("\nPlots generated successfully.")

except FileNotFoundError:
    print("Error: 'results.csv' not found. Please ensure the file is in the same directory as this script.")
except Exception as e:
    print(f"An error occurred: {e}")
