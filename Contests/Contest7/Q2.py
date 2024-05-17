t = int(input())

for _ in range(t):
    n = int(input())
    genders = []
    aviaries = 0
    
    for i in range(n):
        action = int(input())
        
        if action == 1:
            gender = int(input())
            genders.append(gender)
        else:
            if len(genders) > 1 and len(set(genders)) == 2:
                aviaries += 1
            genders = list(set(genders))
            
    if len(genders) > 1 and len(set(genders)) == 2:
        aviaries += 1
        
    print(aviaries)
