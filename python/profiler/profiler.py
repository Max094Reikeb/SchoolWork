import requests
import cProfile


def get_pokemon_list(limit):
    url = "https://pokeapi.co/api/v2/pokemon?limit=" + str(limit)
    response = requests.get(url)
    if response.status_code == 200:
        data = response.json()
        pokemon_list = [pokemon['name'] for pokemon in data['results']]
        return pokemon_list
    else:
        print("Failed to retrieve Pokémon list.")


pokemon_list1 = get_pokemon_list(1000)
pokemon_list2 = get_pokemon_list(100)


def remove_duplicate(list1, list2):
    unique_list = []
    for i in list1:
        if i in unique_list:
            continue
        else:
            unique_list.append(i)
    for j in list2:
        if j in unique_list:
            continue
        else:
            unique_list.append(j)
    return unique_list


unique_pokemon_list = remove_duplicate(pokemon_list1, pokemon_list2)

# print(len(unique_pokemon_list))
# print(unique_pokemon_list)
cProfile.run('remove_duplicate(pokemon_list1, pokemon_list2)', filename='profile_stats.prof')
