class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight
        self.ratio = value / weight  # Value-to-weight ratio

def fractional_knapsack(capacity, items):
    # Sort items by their value-to-weight ratio in descending order
    items.sort(key=lambda x: x.ratio, reverse=True)
    
    total_value = 0
    for item in items:
        if capacity <= 0:  # If the knapsack is full, break
            break
        
        if item.weight <= capacity:
            # Take the whole item
            capacity -= item.weight
            total_value += item.value
        else:
            # Take the fractional part of the item
            total_value += item.value * (capacity / item.weight)
            capacity = 0  # Knapsack is now full

    return total_value

def main():
    n = int(input("Enter the number of items: "))
    items = []

    for i in range(n):
        value = float(input(f"Enter the value of item {i + 1}: "))
        weight = float(input(f"Enter the weight of item {i + 1}: "))
        items.append(Item(value, weight))

    capacity = float(input("Enter the capacity of the knapsack: "))
    max_value = fractional_knapsack(capacity, items)
    
    print(f"The maximum value in the knapsack is: {max_value:.2f}")

if __name__ == "__main__":
    main()
