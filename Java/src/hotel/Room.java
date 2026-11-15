package hotel;

public class Room
{
    public String publicMember = "Public: Accessible from anywhere";
    protected String protectedMember = "Protected: Accessible in subclass (other package)";
    String defaultMember = "Default: Accessible ONLY within 'hotel' package";
    private String privateMember = "Private: Accessible ONLY inside Room class";

    public void showPrivate() {
        System.out.println(privateMember); // Accessible inside same class
    }
}
