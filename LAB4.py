num_users = int(input("Please enter how many users are going to use the application."))
useritems = {}
all_items = set()
for i in range(num_users):
    username = input("Please enter an username.")
    num_items = int(input("Please enter how many items to put inside."))
    item_list = []

    for i in range(num_items):
        item = input("Please enter item")
        item_list.append(item)
        all_items.add(item)
    useritems[username] = item_list


print("ALL USER DATA")

print(all_items)

