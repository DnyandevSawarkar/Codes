T= int(input())
while(T> 0):
    N = int(input())
    inv={}
    for i in range(0,N):
        item_name,item_quantity = map(str,input().split())
        inv[item_name]=int(item_quantity)
    M = int(input())
    for i in range(0,M):
        opr,item_name,quantity=map(str,input().split())
        if(opr=="ADD"):
            if item_name in inv.keys():
                inv[item_name] = int(quantity)
                print(f"UPDATED Item {item_name}")
            else:
                inv[item_name] = int(quantity)
                print(f"ADDED Item {item_name}")
        elif(opr=="DELETE"):
            if item_name in inv.keys():
                if(int(quantity)>inv[item_name]):
                    print(f"Item {item_name} could not be DELETED")
                else:
                    dele = inv[item_name] - int(quantity)
                    inv[item_name] = dele
                    print(f"DELETED Item {item_name}")
            else:
                print(f"Item {item_name} does not exist")
    T-=1
print(f"Total Items in Inventory: {sum(inv.values())}")
    