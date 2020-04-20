#!/usr/bin/python3


def canUnlockAll(boxes):
    my_set_of_keys = set()
    new_set_of_keys = []
    return_value = True
    # print(boxes)
    for box in enumerate(boxes):
        # print("box = {}".format(box[0]))
        # print("new keys = {}".format(box[1]))
        my_set_of_keys.update(box[1])
        for unlock in my_set_of_keys:
            if unlock:
                new_set_of_keys.append(boxes[unlock])
        # print(new_set_of_keys)
        my_set_of_keys.update([key[0] for key in new_set_of_keys if key])
        # print(my_set_of_keys)
        # print(box)
        if box != 0 and box[0] > 0:
            if box[0] in my_set_of_keys:
                return_value = True
            else:
                return False

    return return_value
