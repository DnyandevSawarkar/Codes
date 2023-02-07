todos = []

while True:
    user_input = input("1.Add\n2.Show\n3.Edit\n4.Done\n5.Exit\n\nSelect operation (1, 2, 3, 4, 5): ")
    user_input = user_input.strip()

    match user_input:
        case '1':
            todo_input = input("Enter ToDo task: ")+"\n"
            
            todos.append(todo_input)
            
           
        case '2':
      
            
            for index,item in enumerate(todos):
                item = item.strip('\n')
                print(f"{index+1}-{item}")
            print('\n--------------------------------')    

        case '3':
            todo_number_edit = int(input("Enter ToDo Task Number: ")) - 1
            todos[todo_number_edit] = input("Enter new ToDo: ")

        case '4':
            todo_remove = int(input("Enter ToDo Task Number: ")) - 1
            todos.pop(todo_remove)

        case '5':
            break
        