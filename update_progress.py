def update_readme(day, problems_solved, topics):
    # Read the existing README.md file
    with open("README.md", "r", encoding="utf-8") as file:
        content = file.read()

    # Update the progress value
    import re
    progress_pattern = r"Progress: (\d+) / 160 Days"
    current_progress = int(re.search(progress_pattern, content).group(1))
    
    if day > current_progress:
        content = re.sub(progress_pattern, f"Progress: {day} / 160 Days", content)

    # Append a new row to the progress table
    table_pattern = r"(\| Day \| Problems Solved \| Topics Covered \|[\s\S]*?)\n\|.*?\|\s*\.\.\.\s*\|"
    match = re.search(table_pattern, content)
    
    if match:
        table_content = match.group(1)
        new_line = f"| {day} | {problems_solved} | {topics} |"
        updated_table = table_content + "\n" + new_line
        content = re.sub(table_pattern, updated_table + "\n| ... | ... | ... |", content)

    # Write back the updated content
    with open("README.md", "w", encoding="utf-8") as file:
        file.write(content)

    print(f"Updated progress to Day {day} successfully!")

# Example usage:
update_readme(day=35, problems_solved=1, topics="Kth Missing Element")
