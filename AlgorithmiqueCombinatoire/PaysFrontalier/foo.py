from functools import cmp_to_key

class Country:
    def __init__(self, name):
        self.neighbours = []
        self.name = name
        self.color = None
    
    def print_country(self):
        print(f"{self.name}")
    
    def add_neighbour(self, country):
        self.neighbours.append(country)
    
    def add_neighbours(self, countrys):
        for country in countrys:
            self.neighbours.append(country)       

    @staticmethod
    def set_neighbour(country1, country2):
        country1.add_neighbour(country2)
        country2.add_neighbour(country1)
    
    @staticmethod
    def set_neighbours(main_country, countrys):
        for country in countrys:
            Country.set_neighbour(main_country, country)
    
    def __str__(self):
        return f"<{self.name}, {self.color}>"
    def __repr__(self):
        return str(self)

def country_compare(x, y):
    return len(x.neighbours) - len(y.neighbours)

def checking(begin_country, target, color):
    if(target in begin_country.neighbours):
        return False
    if(target.color != None):
        return False
    for c in target.neighbours:
        if c.color == color:
            return False
    return True

def welsh_powell(countrys):
    
    num_color = 0
    for i, country in enumerate(countrys):
        if(country.color == None):
            country.color = num_color
        else:
            continue

        for x in range(i+1, len(countrys)):
            if(checking(country, countrys[x], num_color)):
                    countrys[x].color = num_color

        num_color +=1
    return None

def main():
    France = Country("France")
    Espagne = Country("Espagne")
    Portugal = Country("Portugal")
    Andorre = Country("Andorre")
    Italie = Country("Italie")
    Autriche = Country("Autriche")
    Suisse = Country("Suisse")
    Allemagne = Country("Allemagne")
    Luxembourg = Country("Luxembourg")
    Belgique = Country("Belgique")
    Pays_bas = Country("Pays_bas")

    France.add_neighbours([Espagne, Andorre, Italie, Suisse, Allemagne, Luxembourg, Belgique])
    Espagne.add_neighbours([France, Andorre, Portugal])
    Portugal.add_neighbours([Espagne])
    Andorre.add_neighbours([Espagne, France])
    Italie.add_neighbours([France, Suisse, Autriche])
    Autriche.add_neighbours([Italie, Suisse, Allemagne])
    Suisse.add_neighbours([France, Italie, Autriche, Allemagne])
    Allemagne.add_neighbours([France, Suisse, Autriche, Luxembourg, Belgique, Pays_bas])
    Luxembourg.add_neighbours([France, Belgique, Allemagne])
    Belgique.add_neighbours([France, Luxembourg, Allemagne, Pays_bas])
    Pays_bas.add_neighbours([Belgique, Allemagne])

    Pays = [France, Espagne, Portugal, Andorre, Italie, Autriche, Suisse, Allemagne, Luxembourg, Belgique, Pays_bas]
    Pays = sorted(Pays, key = cmp_to_key(country_compare), reverse = True)
    #print(Pays)
    welsh_powell(Pays)
    print(Pays)
    

if __name__ == "__main__":
    main()