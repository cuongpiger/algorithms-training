class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        unique_emails = set()
        for email in emails:
            localname, domainname = email.split("@")
            localname = localname.split("+")[0].replace(".", "")
            unique_emails.add(f"{localname}@{domainname}")
        
        return len(unique_emails)
