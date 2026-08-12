def flatten(nested_list):
    """Recursively flattens an arbitrarily nested list."""
    result = []
    for item in nested_list:
        if isinstance(item, list):
            result.extend(flatten(item))
        else:
            result.append(item)
    return result


if __name__ == "__main__":
    data = [1, [2, 3, [4, 5, [6, 7]], 8], 9]
    print(flatten(data))
    # [1, 2, 3, 4, 5, 6, 7, 8, 9]