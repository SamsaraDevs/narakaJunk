function int narakaClassNum(void)
{
    int i;
    for (i = 0; i < CLASSCOUNT; i++)
    {
        if (CheckInventory(NarakaClassItems[i])) { return i; }
    }
    return -1;
}
