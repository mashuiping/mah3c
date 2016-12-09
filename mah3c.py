#!/usr/bin/python
# -*- coding:utf-8 -*-
""" Main program for oh3c.

"""
import ConfigParser
import eapauth
import usermgr
import macmgr
import os

           
def prompt_user_info():
    name = raw_input('Input user name (NetID account):')
    password = raw_input('Input password(NetID password):')
    dev = raw_input('Device(like eth0, eth0.2, eth1, command ''ifconfig'' help you to figure out.): ')
    method = 1
    try:
        method = raw_input('0 stand for XOR, 1 stand for MD5, recommend input 0: ')
    except ValueError:
        print 'Please input a valid number!'
        exit(1)
    if not dev:
        dev = 'eth1'
    mac_address = raw_input('MAC(Press "Enter" if you don\'t need to use binding MAC-address): ')
    if not mac_address:
        mac_address = 'default'
    return name, password, dev, mac_address, method


def main():
    # check for root privilege
    if not (os.getuid() == 0):
        print ('Require the permission of root! add ''sudo'' command ')
        exit(-1)
    um = usermgr.UserMgr()
    login_info = []
    # test whether user info is empty
    if um.get_user_number() == 0:
        choice = raw_input('No user conf file found, create a new one?\n<Y/N>: ')
        if choice == 'y' or choice == 'Y': 
            login_info = prompt_user_info()
            um.create_user(login_info)
        else:
            exit(-1)
    else: 
        users_info = um.get_users_info()
        # print menu
        print '0. Create/Modify user info'
        for i in range(len(users_info)):
            print i+1, users_info[i]
        choice = -1
        while True:
            try:
                choice = int(raw_input('Your choice: '))
            except ValueError:
                print 'Please input a valid number!'
            else:
                break
        # choice to add/modify a user
        if choice == 0:
            login_info = prompt_user_info()
            try:
                um.create_user(login_info)
                print 'Create user info Successfully!'
            except ConfigParser.DuplicateSectionError:
                um.update_user_info(login_info)
                print 'Update user info Successfully!'
        else:
            login_info = um.get_user_info(choice-1)

    # change mac address for binding mac user
    mac_address = login_info[3]
    if mac_address != 'default':
        line_of_mac = macmgr.get_line_of_mac("'wan'")
        if mac_address not in line_of_mac:
            macmgr.change_mac("'wan'", mac_address)
            macmgr.apply_mac()
    # TODO: delete the following line 
    login_info_new = login_info[0:5]
    mah3c = eapauth.EAPAuth(login_info_new)
    mah3c.serve_forever()


if __name__ == "__main__":
    main()
