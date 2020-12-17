#!/usr/bin/python3
"""BEHOLD MY ABOMINATION"""
import requests


def count_words(subreddit, word_list, *args):
    """no loops T_T"""
    # print(args)
    base_url = "https://www.reddit.com"

    data = {"grant_type": "password",
            "username": "jcook0017",
            "password": "temppassword"}

    auth = requests.auth.HTTPBasicAuth("LMsd7o4qaDp3cw",
                                       "KQLYhsl5_Oe1RzvKF-77sqpEYHgGvg")

    try:
        r = args[0]
    except IndexError:
        # print("post")
        r = requests.post(base_url + "/api/v1/access_token",
                          data=data,
                          headers={"user-agent": "0x13 Count it by jcook0017"},
                          auth=auth)

    d = r.json()

    # print(d)

    token = "bearer" + d["access_token"]

    base_url = "https://oauth.reddit.com"

    headers = {"Authorization": token,
               "User-Agent": "0x13 Count it by jcook0017"}

    try:
        result = args[1]
    except IndexError:
        # print("get")
        result = requests.get(base_url + "/r/{}/hot.json".format(subreddit),
                              headers=headers)

    # init vars if not
    try:
        count_word_list = args[3]
    except IndexError:
        count_word_list = 0

    try:
        count_title = args[4]
    except IndexError:
        count_title = 0

    try:
        my_dict = args[2]
    except IndexError:
        my_dict = {}
    # print("my_dict = ", my_dict)
    # print(count_word_list)
    # print(count_title)
    # print(word_list[count_word_list])

    if ((count_title < 25 and not isinstance(my_dict, list) and
         result.status_code == 200)):
        my_stirng = (result
                     .json()["data"]["children"][count_title]["data"]["title"]
                     .lower())
        # print("my_stirng = ", my_stirng)
        my_stirng = my_stirng.lower()

        # print(result.status_code)
        if result.status_code == 200 and count_word_list < len(word_list):
            key = word_list[count_word_list].lower()
            # print(type(key))
            # print(key)
            if my_stirng.find(str(key)) != -1:
                # print(key)
                try:
                    my_dict[key] += my_stirng.count(key)
                except KeyError:
                    my_dict[key] = my_stirng.count(key)
                count_title += 1
                return count_words(subreddit,
                                   word_list,
                                   r,
                                   result,
                                   my_dict,
                                   count_word_list,
                                   count_title)
            else:
                count_word_list += 1
                return count_words(subreddit,
                                   word_list,
                                   r,
                                   result,
                                   my_dict,
                                   count_word_list,
                                   count_title)
        # print("full 'loop'")
        count_word_list = 0
        count_title += 1
        return count_words(subreddit,
                           word_list,
                           r,
                           result,
                           my_dict,
                           count_word_list,
                           count_title)
    elif count_title == 25 and result.status_code == 200:
        # print(count_title)
        count_title = 0
        count_word_list = 0
        # print("after")
        after = result.json()["data"]["after"]
        # print(after)
        result = requests.get(base_url + "/r/{}/hot.json&after={}"
                              .format(subreddit, after),
                              headers=headers)
        return count_words(subreddit,
                           word_list,
                           r,
                           result,
                           my_dict,
                           count_word_list,
                           count_title)

    else:
        if not isinstance(my_dict, list):
            # print(my_dict)
            my_dict = sorted(my_dict.items(),
                             key=lambda x: (x[1], x[0]),
                             reverse=True)
            # print(my_dict)
        try:
            list_count = args[5]
        except IndexError:
            list_count = 0
        if list_count < len(my_dict):
            print(my_dict[list_count][0], ": ", my_dict[list_count][1])
            list_count += 1
            return count_words(subreddit,
                               word_list,
                               r,
                               result,
                               my_dict,
                               count_word_list,
                               count_title,
                               list_count)
