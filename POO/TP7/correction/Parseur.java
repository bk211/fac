import java.io.Reader;
import java.io.FileReader;
import java.io.PushbackReader;
import java.io.IOException;

public class Parseur
{
    private PushbackReader input; // le flot d'entree

    static final private int OKAY = 0;
    static final private int EOL = 1;
    static final private int EOF = 2;

    public Parseur(Reader r)
    {
        input = new PushbackReader(r);
        skipBlanks(true);
    }

    public Parseur(String filename)
    {
        Reader r = null;
        try {
            r = new FileReader(filename);
        } catch(IOException e) {
            System.err.println("Impossible d'ouvrir le fichier " +
                               filename +
                               " raison: " + e);
            System.exit(2);
        }

        input = new PushbackReader(r);
        skipBlanks(true);
    }

    /* suivant: lit le mot suivant.  
       Retourne une chaine vide a la fin d'un paragraphe.
       Retourne null a la fin du fichier, et termine le programme s'il
       y a erreur. */

    public String suivant()
    {
        int i;
        char c;
        StringBuffer s;
        int result;

        result = skipBlanks(false);
        if(result == EOF)
            return null;
        else if(result == EOL) {
            skipBlanks(true);
            return "";
        }

        s = new StringBuffer();

        try {
            while(true) {
                i = -1;
                i = input.read();
                if(i < 0)
                    return null;
                c = (char)i;

                if(c == ' ' || c == '\t') {
                    skipBlanks(false);
                    break;
                } else if(c == '\n') {
                    skipBlanks(false);
                    break;
                } else
                    s.append(c);
            }
        } catch(IOException e) {
            System.err.println("Impossible de lire, raison: " + e);
            System.exit(2);
        }

        return s.toString();
    }

    /* skipBlancs: ignore les caracteres blancs dans le flot d'entree.
       Si newlines est vrai, ignore les fins de ligne.
       retourne EOL si l'on a trouve une fin de ligne, EOF si le fichier se
       termine, et termine le programme s'il y a erreur. */

    private int skipBlanks(boolean newlines)
    {
        int i;
        char c;
        boolean foundeol = false;
        while(true) {
            i = -1;
            try {
                i = input.read();
            } catch(IOException e) {
                System.err.println("Impossible de lire, raison: " + e);
                System.exit(2);
            }
            if(i < 0)
                return EOF;
            c = (char)i;

            if(c == ' ' || c == '\t') {
                continue;
            } else if(c == '\n') {
                foundeol = true;
                if(newlines)
                    continue;
                else
                    break;
            } else {
                break;
            }
        }

        if(i >= 0 && (!newlines || i != '\n')) {
            try {
                input.unread(i);
            } catch(IOException e) {
                System.err.println("Impossible de remettre, raison: " + e);
                System.exit(2);
            }
        }

        if(foundeol)
            return EOL;
        else
            return OKAY;
    }
}
