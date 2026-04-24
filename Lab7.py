class Vehicle:
    def __init__(self,vid,model,year):
        self.vid = vid
        self.model = model
        self.year = int(year)


    def __str__(self):
        return str(self.vid)+","+str(self.year)+","+str(self.model)

    def __eq__(self, other):
        return self.vid == other.vid

    def is_new(self,n):
        return self.year >= (2026-n)


class Car(Vehicle):
    def __init__(self, vid, model, year,fuel_type,doors):
        super().__init__(vid, model, year)
        self.fuel_type = fuel_type
        self.doors = int(doors)

    def __str__(self):
        return str(self.vid) + "," + str(self.year) + "," + str(self.model)+","+str(self.fuel_type)+","+str(self.doors)


class Truck(Vehicle):
    def __init__(self, vid, model, year,max_load,axles):
        super().__init__(vid, model, year)
        self.max_load = int(max_load)
        self.axles = int(axles)

    def __str__(self):
        return str(self.vid) + "," + str(self.year) + "," + str(self.model)+","+str(self.max_load)+","+str(self.axles)

class Motorcycle(Vehicle):
    def __init__(self, vid, model, year,engine_cc,type):
        super().__init__(vid, model, year)
        self.engine_cc = int(engine_cc)
        self.type = type

    def __str__(self):
        return str(self.vid) + "," + str(self.year) + "," + str(self.model)+","+str(self.engine_cc)+","+str(type)

def save_fleet_to_file(vehicles,filename):
    file = open(filename+".txt","w",encoding="utf-8")
    for v in vehicles:
        if type(v) == Car:
            file.write("Car,"+v.vid+","+v.model+","+str(v.year)+","+v.fuel_type+","+str(v.doors)+"\n")
        elif type(v) ==Truck:
            file.write("Truck"+v.vid+","+v.model+","+str(v.year)+","+str(v.max_load)+","+str(v.axles)+"\n")
        elif type(v)==Motorcycle:
            file.write("Motorcyle"+v.vid+","+v.model+","+str(v.year)+","+str(v.engine_cc)+","+v.type+"\n")
    file.close()

def load_fleet_from_file(filename):
    file = open(filename+".txt","r")
    for line in file:
        print(line.strip())
    file.close()


car1=Car("vid1","Tesla",2000,"electric",4)
car2=Car("vid2","Opel",2020,"LPG",2)
truck1=Truck("vid3","Scania",1990,500,4)
truck2=Truck("vid4","Mercedes",2010,1000,2)
motocycle1=Motorcycle("vid5","Yamaha",2025,300,"Sport")
motocycle2=Motorcycle("vid6","Kuzuki",2021,150,"Crusier")
vehicles = [car1,car2,truck1,truck2,motocycle1,motocycle2]

save_fleet_to_file(vehicles,"deneme")
load_fleet_from_file("deneme")