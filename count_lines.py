import os

def count_cpp_stats(directory):
    cpp_count = 0
    h_count = 0
    total_lines = 0

    for root, dirs, files in os.walk(directory):
        # Modifying dirs in-place prevents os.walk from entering them
        if 'out' in dirs:
            dirs.remove('out')
            
        for file in files:
            if file.endswith('.cpp') or file.endswith('.h'):
                if file.endswith('.cpp'):
                    cpp_count += 1
                else:
                    h_count += 1
                
                file_path = os.path.join(root, file)
                try:
                    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                        total_lines += sum(1 for line in f if line.strip())
                except Exception as e:
                    print(f"Could not read {file_path}: {e}")

    print(f"--- Results (excluding 'out' folder) ---")
    print(f".cpp files: {cpp_count}")
    print(f".h files:   {h_count}")
    print(f"Total LOC (non-blank): {total_lines}")

if __name__ == "__main__":
    path = input("Enter the folder path: ").strip()
    if os.path.isdir(path):
        count_cpp_stats(path)
    else:
        print("Invalid directory.")
