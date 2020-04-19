#!/usr/bin/python3


def canUnlockAll(boxes):
    my_set_of_keys = set()
    return_value = False
    box_number = 0
    for values in boxes:
        if values:
            my_set_of_keys.update(values)
        (_, *key_numbers) = enumerate(my_set_of_keys, 0)
        if key_numbers and box_number != 0:
            if box_number in list(sum(key_numbers, ())):
                return_value = True
            else:
                return False
        box_number += 1

    return return_value
