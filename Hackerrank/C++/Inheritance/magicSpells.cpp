if (Fireball *fireball = dynamic_cast<Fireball *>(spell))
{
    fireball->revealFirepower();
}
else if (Frostbite *frostbite = dynamic_cast<Frostbite *>(spell))
{
    frostbite->revealFrostpower();
}
else if (Thunderstorm *thunderstorm = dynamic_cast<Thunderstorm *>(spell))
{
    thunderstorm->revealThunderpower();
}
else if (Waterbolt *waterbolt = dynamic_cast<Waterbolt *>(spell))
{
    waterbolt->revealWaterpower();
}
else
{
    string spellName = spell->revealScrollName();
    string spellJournal = SpellJournal::read();
    int nameLength = spellName.length();
    int journalLength = spellJournal.length();
    int array[nameLength + 1][journalLength + 1];
    for (int i = 0; i <= nameLength; i++)
    {
        array[i][0] = 0;
    }
    for (int j = 0; j <= journalLength; j++)
    {
        array[0][j] = 0;
    }
    for (int i = 1; i <= nameLength; i++)
    {
        for (int j = 1; j <= journalLength; j++)
        {
            if (spellName[i - 1] == spellJournal[j - 1])
            {
                array[i][j] = array[i - 1][j - 1] + 1;
            }
            else
            {
                array[i][j] = max(array[i][j - 1], array[i - 1][j]);
            }
        }
    }
    cout << array[nameLength][journalLength] << endl;
}